#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Glsl.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <cmath>
#include <iostream>

bool hasCollided(sf::CircleShape &circle1, sf::CircleShape &circle2);

class Vec2 {
public:
  float x = 0, y = 0;
  Vec2() {}
  Vec2(Vec2 &&) = default;
  Vec2(const Vec2 &) = default;

  Vec2(float xin, float yin) : x(xin), y(yin) {}

  float length() {
    return std::sqrt(x * x + y * y);
  }

  Vec2& add(const Vec2 &v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vec2& scale(float scale) {
    x *= scale;
    y *= scale;
    return *this;
  }

  Vec2 operator+ (const Vec2 &rhs) {
    return Vec2(x + rhs.x, y + rhs.y);
  }
  Vec2 operator* (float rhsScale) {
    return Vec2(x * rhsScale , y * rhsScale);
  }

  ~Vec2(){ }
};

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Learning",
                          sf::Style::Resize);
  window.setFramerateLimit(60);

  sf::CircleShape bCircle(50.0f);
  sf::Vector2f bCirclePos = {0.f, 250.0f};
  sf::Vector2f bCircleDir = {-1.f, 0.f};
  bCircle.setFillColor(sf::Color::Blue);

  sf::CircleShape rCircle(50.0f);
  sf::Vector2f rCirclePos = {700.f, 250.0f};
  sf::Vector2f rCircleDir = {1.f, 0.f};
  rCircle.setFillColor(sf::Color::Red);

  float speed = 3.0f;

  Vec2 v1 = Vec2(250.0f, 530.0f);
  Vec2 v2 = Vec2(850.0f, 330.0f);
  Vec2 v3 = (v1 + v2) * 2;
  v1.add(v2).scale(2).add(v3);
  

  std::cout << v3.x << ", " << v3.y << '\n';
  std::cout << v1.x << ", " << v1.y << '\n';

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Q)
          window.close();
      } else if (const auto *resized = event->getIf<sf::Event::Resized>()) {
        std::cout << "new width: " << resized->size.x << '\n';
        std::cout << "new height: " << resized->size.y << '\n';
      }
      if (const auto *mouseButtonPressed =
              event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
          std::cout << "the left button was pressed" << '\n';
          std::cout << "mouse x: " << mouseButtonPressed->position.x << '\n';
          std::cout << "mouse y: " << mouseButtonPressed->position.y << '\n';
        }
      }
    }

    // bCirclePos += bCircleDir * speed;
    // rCirclePos += rCircleDir * speed;

    // if (hasCollided(bCircle, rCircle)) {
    //   bCircleDir = bCircleDir * -1.0f;
    //   rCircleDir = rCircleDir * -1.0f;
    // }

    // bCircle.setPosition(bCirclePos);
    // rCircle.setPosition(rCirclePos);

    window.clear(sf::Color::Black);
    // window.draw(bCircle);
    // window.draw(rCircle);
    window.display();
  }

  return 0;
}

bool hasCollided(sf::CircleShape &circle1, sf::CircleShape &circle2) {
  sf::Rect<float> circle2Boundary = circle2.getGlobalBounds();
  if (circle1.getGlobalBounds().findIntersection(circle2Boundary))
    return true;
  else
    return false;
}
