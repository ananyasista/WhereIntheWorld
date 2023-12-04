#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "What In The World?");

    // top bar
    sf::RectangleShape topBar(sf::Vector2f(800.f, 60.f));
    topBar.setFillColor(sf::Color::White);
    topBar.setPosition(0.f, 0.f);

    //background rectangle
    sf::RectangleShape background(sf::Vector2f(800.f, 800.f));
    background.setFillColor(sf::Color(253, 250, 236));
    background.setPosition(0.f, 0.f);

    //load the logo
    sf::Texture logoTexture;
    if (!logoTexture.loadFromFile("../tripLogo.png"))
    {
        return EXIT_FAILURE;
    }

    // Create the logo sprite
    sf::Sprite logoSprite(logoTexture);
    float scale = 0.1;
    logoSprite.setScale(scale, scale);
    logoSprite.setPosition(0.f, 0.f);

    sf::Font font;
    if (!font.loadFromFile("../arial.ttf"))
    {
        return EXIT_FAILURE;
    }

    sf::Text text("Where In The World?", font, 20);
    text.setPosition(logoSprite.getGlobalBounds().width + 10.f, 20.f);
    text.setFillColor(sf::Color::Black);

    //start trip box
    sf::RectangleShape tripBox(sf::Vector2f(300.f, 600.f));
    tripBox.setFillColor(sf::Color::White);
    tripBox.setPosition(20.f, 100.f);

    //start text
    sf::Text startText("Start:", font, 20);
    startText.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 10.f);
    startText.setFillColor(sf::Color::Black);

    //start box
    sf::RectangleShape startInputBox(sf::Vector2f(280.f, 30.f));
    startInputBox.setFillColor(sf::Color::Black);
    startInputBox.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 40.f);

    //start input
    sf::Text startInput("", font, 20);
    sf::String startCity;
    startInput.setPosition(tripBox.getPosition().x + 15.f, tripBox.getPosition().y + 40.f);
    startInput.setFillColor(sf::Color::White);


    //destination text
    sf::Text destText("Destination:", font, 20);
    destText.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 110.f);
    destText.setFillColor(sf::Color::Black);

    //destination place
    sf::RectangleShape destInputBox(sf::Vector2f(280.f, 30.f));
    destInputBox.setFillColor(sf::Color::Black);
    destInputBox.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 140.f);

    //destination input
    sf::Text desInput("", font, 20);
    sf::String finalDestination;
    desInput.setPosition(tripBox.getPosition().x + 15.f, tripBox.getPosition().y + 140.f);
    desInput.setFillColor(sf::Color::White);

    //user swtich between start and destination
    enum State {
        inputStartCity,
        inputDestination
    };
    State current = inputStartCity;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //user input
            if(event.type == sf::Event::TextEntered) {
                if(event.text.unicode == 8) {
                    if(current == inputStartCity && !startCity.isEmpty()) {
                        startCity.erase(startCity.getSize() -1);
                    }
                    else if (current == inputDestination && !finalDestination.isEmpty()) {
                        finalDestination.erase(finalDestination.getSize() - 1);
                    }
                }
                else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    if(current == inputStartCity) {
                        startCity += static_cast<char>(event.text.unicode);
                    }
                    else if(current == inputDestination) {
                        finalDestination += static_cast<char>(event.text.unicode);
                    }
                }
            }

            //switch input when user press enter
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                if(current == inputStartCity) {
                    current = inputDestination;
                }
                std::cout << "Start City: " << startCity.toAnsiString() << std::endl;
            }
        }

        window.clear(sf::Color(210, 180, 140));

        window.draw(background);
        window.draw(topBar);
        window.draw(logoSprite);
        window.draw(text);

        window.draw(tripBox);
        window.draw(startText);
        window.draw(startInputBox);
        window.draw(startInput);
        window.draw(destText);
        window.draw(destInputBox);
        window.draw(destInputBox);

        startInput.setString(startCity);
        if(current == inputDestination) {
            desInput.setString(finalDestination);
        }

        window.display();
    }

    return 0;
}
