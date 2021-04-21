#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  sf::Font font;

  sf::Texture texture;
  // 512 x 605
  // 170 x 200
  if (!texture.loadFromFile("tank.png", sf::IntRect(0, 0, 170, 200))) {
    // error...
  }


  if (!font.loadFromFile("C:/Users/Marius/Desktop/GrafineBiblioteka/raleway/Raleway-Black.ttf")) {
    // error...
  }
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sf::Text text;
  text.setFont(font);

  text.setFillColor(sf::Color::White);
  text.setCharacterSize(24); // in pixels, not points!

  text.setString("Default reiksme");
  // run the program as long as the window is open



  while (window.isOpen()) {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {


//      float x = sprite.getPosition().x;
//      float y = sprite.getPosition().y;
//
//
//      sf::sleep(sf::milliseconds(1000));
//      sprite.setPosition(x, y+speed);

      float speed = 10.0f;
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();


      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        float rotate = 0;
        // get the local mouse position (relative to a window)
        sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window

       // left mouse button is pressed: shoot
        std::cout << "x=" << localPosition.x << ", y=" << localPosition.y << std::endl;

        rotate+= 45.f;
        sprite.setRotation((rotate));
      }


      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        text.setString("Paspaudziau i virsu");
        float x = sprite.getPosition().x;
        float y = sprite.getPosition().y;
        sprite.setPosition(x, y - speed);

      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        text.setString("Paspaudziau i apacia");
        float x = sprite.getPosition().x;
        float y = sprite.getPosition().y;
        sprite.setPosition(x, y + speed);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        float x = sprite.getPosition().x;
        float y = sprite.getPosition().y;
        sprite.setPosition(x - speed, y);
        text.setString("Paspaudziau i kaire");
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        text.setString("Paspaudziau i desine");
        float x = sprite.getPosition().x;
        float y = sprite.getPosition().y;
        sprite.setPosition(x + speed, y);



        //window.draw(sprite);

      }

      window.clear(sf::Color::Black);

      window.draw(sprite);
      window.draw(text);
      //window.draw(sprite);
      window.display();
    }



  }

  return 0;
}
