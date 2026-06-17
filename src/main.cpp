#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Learning");
  window.setFramerateLimit(60);

  sf::CircleShape circle(50.0f);
  circle.setFillColor(sf::Color::Green);
  circle.setPosition({375.f, 275.f});

  while (window.isOpen()) {

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    window.clear(sf::Color(sf::Color::Black));
    window.draw(circle);
    window.display();
  }

  return 0;
}
