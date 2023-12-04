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
    if (!logoTexture.loadFromFile("../images/tripLogo.png"))
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

    //map point image
    sf::Texture pointTexture;
    if (!pointTexture.loadFromFile("../images/mapPoint.png"))
    {
        return EXIT_FAILURE;
    }

    // Create the point sprite
    sf::Sprite pointSprite(pointTexture);
    float pointScale = 0.05;
    pointSprite.setScale(pointScale, pointScale);
    pointSprite.setPosition(tripBox.getPosition().x - 30.f, tripBox.getPosition().y + 10.f);

    //start text
    sf::Text startText("Start:", font, 20);
    startText.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 10.f);
    startText.setFillColor(sf::Color::Black);

    //start city box
    sf::RectangleShape startCityBox(sf::Vector2f(120.f, 30.f));
    startCityBox.setFillColor(sf::Color::Black);
    startCityBox.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 40.f);

    //start city input
    sf::Text startCityInput("", font, 20);
    sf::String startCity;
    startCityInput.setPosition(tripBox.getPosition().x + 15.f, tripBox.getPosition().y + 40.f);
    startCityInput.setFillColor(sf::Color::White);

    //start country box
    sf::RectangleShape startCountryBox(sf::Vector2f(120.f, 30.f));
    startCountryBox.setFillColor(sf::Color::Black);
    startCountryBox.setPosition(tripBox.getPosition().x + 150.f, tripBox.getPosition().y + 40.f);

    //start country input
    sf::Text startCountryInput("", font, 20);
    sf::String startCountry;
    startCountryInput.setPosition(tripBox.getPosition().x + 155.f, tripBox.getPosition().y + 40.f);
    startCountryInput.setFillColor(sf::Color::White);


    //destination text
    sf::Text destText("Enter your Destination:", font, 20);
    destText.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 110.f);
    destText.setFillColor(sf::Color::Black);

    //destination city box
    sf::RectangleShape destInputBox(sf::Vector2f(120.f, 30.f));
    destInputBox.setFillColor(sf::Color::Black);
    destInputBox.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 140.f);

    //destination city input
    sf::Text desCityInput("", font, 20);
    sf::String cityDestination;
    desCityInput.setPosition(tripBox.getPosition().x + 15.f, tripBox.getPosition().y + 140.f);
    desCityInput.setFillColor(sf::Color::White);

    //destination country box
    sf::RectangleShape destCountryBox(sf::Vector2f(120.f, 30.f));
    destCountryBox.setFillColor(sf::Color::Black);
    destCountryBox.setPosition(tripBox.getPosition().x + 150.f, tripBox.getPosition().y + 140.f);

    //destination country input
    sf::Text desCountryInput("", font, 20);
    sf::String countryDestination;
    desCountryInput.setPosition(tripBox.getPosition().x + 160.f, tripBox.getPosition().y + 140.f);
    desCountryInput.setFillColor(sf::Color::White);

    //drive method text
    sf::Text driveText("Driving Method:", font, 20);
    driveText.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 200.f);
    driveText.setFillColor(sf::Color::Black);

    //dijkstra button
    sf::RectangleShape dijkstraButton(sf::Vector2f(120.f, 30.f));
    dijkstraButton.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 240.f);
    dijkstraButton.setFillColor(sf::Color::Black);
    sf::Text dijText("Dijkstra", font, 20);
    dijText.setPosition(dijkstraButton.getPosition().x + 30.f, dijkstraButton.getPosition().y + 5.f);
    dijText.setFillColor(sf::Color::White);


    //prims button
    sf::RectangleShape primsButton(sf::Vector2f(120.f, 30.f));
    primsButton.setPosition(tripBox.getPosition().x + 140.f, tripBox.getPosition().y + 240.f);
    primsButton.setFillColor(sf::Color::Black);
    sf::Text primText("Prims", font, 20);
    primText.setPosition(primsButton.getPosition().x + 30.f, primsButton.getPosition().y + 5.f);
    primText.setFillColor(sf::Color::White);

    //reset button
    sf::RectangleShape resetButton(sf::Vector2f(120.f, 30.f));
    resetButton.setPosition(tripBox.getPosition().x + 90.f, tripBox.getPosition().y + 500.f);
    resetButton.setFillColor(sf::Color::Black);
    sf::Text resetText("Reset Trip!", font, 20);
    resetText.setPosition(resetButton.getPosition().x + 10.f, resetButton.getPosition().y + 5.f);
    resetText.setFillColor(sf::Color::White);

    //TEMP window after button click
    sf::RenderWindow drivingWindow(sf::VideoMode(400, 200), "Loading");
    drivingWindow.setVisible(false);

    //user switch between start and destination
    enum State {
        inputStartCity,
        inputStartCountry,
        inputDesCity,
        inputDesCountry
    };
    State current = inputStartCity;

    // scrolling trip iternary
    sf::Text tripIternary("Trip Iternary: ", font, 20);
    tripIternary.setFillColor(sf::Color::Black);
    tripIternary.setPosition(350.f, 200.f);
    tripIternary.setString("Testing (Add Backend function here to get Iternary)\nTest\na\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nyay");
    sf::View view(sf::FloatRect(0, 0, 800, 800));

    //text box editing
    bool editing = false;
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
                    else if (current == inputStartCountry && !startCountry.isEmpty()) {
                        startCountry.erase(startCountry.getSize() - 1);
                    }
                    else if (current == inputDesCity && !cityDestination.isEmpty()) {
                        cityDestination.erase(cityDestination.getSize() - 1);
                    }
                    else if (current == inputDesCountry && !countryDestination.isEmpty()) {
                        countryDestination.erase(countryDestination.getSize() - 1);
                    }
                }
                else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    if(current == inputStartCity) {
                        startCity += static_cast<char>(event.text.unicode);
                    }
                    else if(current == inputStartCountry) {
                        startCountry += static_cast<char>(event.text.unicode);
                    }
                    else if(current == inputDesCity) {
                        cityDestination += static_cast<char>(event.text.unicode);
                    }
                    else if(current == inputDesCountry) {
                        countryDestination += static_cast<char>(event.text.unicode);
                    }
                }

//                //user input mouse click
//                if(event.type == sf::Event::MouseButtonPressed){
//                    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
//
//                    //start city
//                    if(startCityBox.getGlobalBounds().contains(mousePos)) {
//                        editing = !editing;
//                        if(editing) {
//                            startCity.clear();
//                        }
//                    } else if(startCountryBox.getGlobalBounds().contains(mousePos)) {
//                        editing = !editing;
//                        if(editing) {
//                            startCountry.clear();
//                        }
//                    } else if(desCityInput.getGlobalBounds().contains(mousePos)) {
//                        editing = !editing;
//                        if (editing) {
//                            cityDestination.clear();
//                        }
//                    } else if(desCountryInput.getGlobalBounds().contains(mousePos)) {
//                        editing = !editing;
//                        if (editing) {
//                            countryDestination.clear();
//                        }
//                    }
//                }
            }

            //switch input when user press ENTER
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                if(current == inputStartCity) {
                    current = inputStartCountry;
                }
                else if(current == inputStartCountry) {
                    current = inputDesCity;
                }
                else if(current == inputDesCity) {
                    current = inputDesCountry;
                }
                //temp test
                std::cout << "Start City: " << startCity.toAnsiString() << std::endl;
                std::cout << "Start Country: " << startCountry.toAnsiString() << std::endl;
                std::cout << "Destination City: " << cityDestination.toAnsiString() << std::endl;
                std::cout << "Destination Country: " << countryDestination.toAnsiString() << std::endl;
            }


//            //input editing mode
//            if(editing) {
//                if (sf::milliseconds(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ? 1 : 0).asMilliseconds() > 500) {
//                    startCityInput.setString(startCity + "|");
//                } else {
//                    startCityInput.setString(startCity);
//                }
//            }

            //driving button clicks
            if(event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

                //dijkstra button
                if(dijkstraButton.getGlobalBounds().contains(mousePos)) {
                    cout << "Dijkstra Trip!" << endl; //call meethod here
                    drivingWindow.setVisible(true);
                }
                //prims button
                else if(primsButton.getGlobalBounds().contains(mousePos)) {
                    cout << "Prims Trip!" << endl; //call method here
                    drivingWindow.setVisible(true);
                } else if(resetButton.getGlobalBounds().contains(mousePos)) {
                    //resets input fields
                    startCity.clear();
                    startCountry.clear();
                    cityDestination.clear();
                    countryDestination.clear();

                    //starts back at input start city
                    current = inputStartCity;
                    cout << "Trip Reset!" << endl;
                }
            }
            // scrolling
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Up and view.getCenter().y - view.getSize().y / 2 > 0) {
                    view.move(0, -10);
                } else if (event.key.code == sf::Keyboard::Down and view.getCenter().y + view.getSize().y / 2 < tripIternary.getGlobalBounds().height)
                        view.move(0, 10);
            }
        }
        // scrolling
        window.setView(view);

        window.clear(sf::Color(210, 180, 140));

        window.draw(background);
        window.draw(topBar);
        window.draw(logoSprite);
        window.draw(text);

        window.draw(tripBox);
        window.draw(pointSprite);
        window.draw(startText);
        window.draw(startCityBox);
        window.draw(startCityInput);
        window.draw(startCountryBox);
        window.draw(startCountryInput);

        window.draw(destText);
        window.draw(destInputBox);
        window.draw(desCityInput);
        window.draw(destCountryBox);
        window.draw(desCountryInput);

        //start & destination strings
        startCityInput.setString(startCity);
        startCountryInput.setString(startCountry);
        desCityInput.setString(cityDestination);
        desCountryInput.setString(countryDestination);

        if(current == inputDesCity) {
            desCityInput.setString(cityDestination);
        } else if(current == inputStartCity) {
            startCityInput.setString(startCity);
        } else if(current == inputStartCountry) {
            startCountryInput.setString(startCountry);
        } else if(current == inputDesCountry) {
            desCountryInput.setString(countryDestination);
        }

        window.draw(driveText);
        window.draw(dijkstraButton);
        window.draw(dijText);
        window.draw(primsButton);
        window.draw(primText);

        window.draw(resetButton);
        window.draw(resetText);

        // scrolling
        window.draw(tripIternary);

        window.display();

        //driving window
        sf::Event driving;
        while(drivingWindow.pollEvent(driving)) {
            if(driving.type == sf::Event::Closed) {
                drivingWindow.close();
            }
        }
        drivingWindow.clear(sf::Color::White);
        drivingWindow.display();
    }

    return 0;
}

/*.
     * sf::Text tripIternary("Trip Iternary: ", font, 20);
     * tripIternary.setFillColor(sf::Color::Black);
     * tripIternay.setPosition(tripBox.getPosition().x + 300.f, tripBox.getPosition().y + 40.f);
     * tripIternary.setString("Testing (Add Backend function here to get Iternary) aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
     * sf::View view(sf::FloatRect(300, 60, 800, 800));
 * add to poll Event while loop
 * if(event.type == sf::Event::KeyPressed) {
 * switch(event.key.code) {
 * case sf::Keyboard::Up:
 * view.move(0, -10);
 * break;
 * case sf::Keyboard::Down:
 * view.move(0, 10);
 * break;
 * default:
 * break;
 * }
 * window.setView(view);
 * window.draw(tripIternary);
 * */