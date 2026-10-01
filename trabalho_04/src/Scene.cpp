#include "../include/Scene.h"
#include <cmath>
#include <memory>

Scene::Scene(SDL_Window** window, SDL_Renderer** renderer, double aspect_ratio, int window_width, double viewport_height,  double distance_viewport, Camera eye) : window{window}, renderer{renderer}, aspect_ratio{aspect_ratio}, window_width{window_width}, viewport_height{viewport_height}, distance_viewport{distance_viewport}, eye{eye}{
    window_height = int(window_width / aspect_ratio);
    window_height = (window_height < 1) ? 1 : window_height;
    viewport_width = viewport_height * (double(window_width)/window_height);
    Vec3 viewport_horizontal(viewport_width, 0, 0);
    Vec3 viewport_vertical(0, -viewport_height, 0);
    pixel_delta_horizontal = viewport_horizontal / window_width;
    pixel_delta_vertical = viewport_vertical / window_height;
    Vec3 viewport_upper_left = eye.point - Vec3(0, 0, distance_viewport) - viewport_horizontal / 2 - viewport_vertical / 2;
    pixel00_loc = viewport_upper_left + (pixel_delta_horizontal + pixel_delta_vertical) * 0.5;
}
int Scene::getWidth() { return window_width; }
int Scene::getHeight() { return window_height; }
void Scene::addObject(std::shared_ptr<Shape> object) { objects.push_back(object); }
void Scene::addLight(std::shared_ptr<Light> light) { lights.push_back(light); }
void Scene::setAmbientLight(Vec3 light) { ambient_light = light; }
Vec3 Scene::pixelColor(std::shared_ptr<Shape> s, Vec3& dir, Vec3 point) {
    Vec3 e_ret = ambient_light.cross_at(s->color.k_amb);
    for (const std::shared_ptr<Light>& light : lights) {
        // Verificando se não tem sombra
        Vec3 l = (light->position - point);
        Ray light_ray(point, l);
        bool isShadow = false;
        for (const std::shared_ptr<Shape>& object : objects) {
            if (object != s) {
                double t = object->intercepts(light_ray);
                if (t > 0.0 and t < 1.0) {
                    isShadow = true;
                    break;
                }
            }
        }
        if (!isShadow) {
            l = l.norm();
            Vec3 v = (dir * -1.0).norm();
            Vec3 n = s->getNormal(point);
            Vec3 r = n * (2.0 * (l.dot(n))) - l;
            double nl = n.dot(l);
            double rv = r.dot(v);
            Vec3 e_dif = (nl > 0.0) ? light->intensity.cross_at(s->color.k_dif) * nl : Vec3 {0, 0, 0};
            Vec3 e_esp = (rv > 0.0) ? light->intensity.cross_at(s->color.k_esp) * pow(rv, s->color.alpha) : Vec3 {0, 0, 0};
            e_ret = e_ret + e_dif + e_esp;
        }
    }
    if (e_ret.x > 1.0) e_ret.x = 1.0;
    if (e_ret.y > 1.0) e_ret.y = 1.0;
    if (e_ret.z > 1.0) e_ret.z = 1.0;
    return e_ret;
}
void Scene::drawFrame() {
    for (int l = 0; l < window_height; ++l) {
        for (int c = 0; c < window_width; ++c) {
            Vec3 pixel_center = pixel00_loc + (pixel_delta_horizontal * c) + (pixel_delta_vertical * l);
            Vec3 ray_direction = pixel_center - eye.point;
            Ray r(eye.point, ray_direction.norm());
            double closest_so_far = INFINITY;
            Vec3 color(0, 0, 0);
            for (const std::shared_ptr<Shape>& object : objects) {
                double t = object->intercepts(r);
                if (t >= 0.0 and t < closest_so_far) {
                    closest_so_far = t;
                    color = pixelColor(object, ray_direction, r.at(t));
                }
            }
            SDL_SetRenderDrawColor(*renderer, int(color.x * 255.999), int(color.y * 255.999), int(color.z * 255.999), SDL_ALPHA_OPAQUE); // Sphere color
            SDL_RenderPoint(*renderer, c, l);
        }
    }
}
