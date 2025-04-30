#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
int losowanie(int zakres)
{
    int los =rand()%zakres;
    if(los<100)
        los = 100;
    if(rand()%2==0)
        los=-los;
    return los;
}
int main() {
    srand(time(NULL));
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing circle");
    // create some shapes
    sf::CircleShape circle(20.0);
    circle.setPosition(rand()%800, rand()%600);
    circle.setFillColor(sf::Color::Red);

    sf::Clock clock;

    float v_x=losowanie(500), v_y = losowanie(500);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        circle.move(v_x*elapsed.asSeconds(),v_y*elapsed.asSeconds());
        sf::FloatRect circle_bound=circle.getGlobalBounds();
        if (circle_bound.left < 0) {
            v_x = -v_x;
            circle.setPosition(0, circle_bound.top);
        }
        if (circle_bound.top < 0) {
            v_y = -v_y;
            circle.setPosition(circle_bound.left, 0);
        }
        if (circle_bound.left + circle_bound.width > window.getSize().x) {
            v_x = -v_x;
            circle.setPosition(window.getSize().x - circle_bound.width, circle_bound.top);
        }
        if (circle_bound.top + circle_bound.height > window.getSize().y) {
            v_y = -v_y;
            circle.setPosition(circle_bound.left, window.getSize().y - circle_bound.height);
        }
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(circle);

        window.display();
    }

    return 0;
}
