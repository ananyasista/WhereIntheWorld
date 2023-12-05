#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "What In The World?");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/map.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite background(backgroundTexture);

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

    // loading fonts
    sf::Font fontHead;
    if (!fontHead.loadFromFile("../fonts/Tillana-SemiBold.ttf"))
        return EXIT_FAILURE;
    sf::Font fontSub;
    if (!fontSub.loadFromFile("../fonts/Sansita-Regular.ttf"))
        return EXIT_FAILURE;
    sf::Font fontBody;
    if (!fontBody.loadFromFile("../fonts/Prompt-Light.ttf"))
        return EXIT_FAILURE;

    sf::Text text("Where In The World?", fontHead, 20);
    text.setPosition(logoSprite.getGlobalBounds().width + 10.f, 20.f);
    text.setFillColor(sf::Color(25, 39, 56));

    // top bar
    sf::RectangleShape topBar(sf::Vector2f(300.f, 60.f));
    topBar.setFillColor(sf::Color(250, 241, 237));
    topBar.setPosition(20.f, 100.f);

    //start trip box
    sf::RectangleShape tripBox(sf::Vector2f(300.f, 640.f));
    tripBox.setFillColor(sf::Color(250, 241, 237));
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
    pointSprite.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 20.f);
    sf::Sprite pointSprite2(pointTexture);
    pointSprite2.setScale(pointScale, pointScale);
    pointSprite2.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 105.f);


    //start text
    sf::Text startText("Start:", fontSub, 30);
    startText.setPosition(tripBox.getPosition().x + 40.f, tripBox.getPosition().y + 15.f);
    startText.setFillColor(sf::Color(25, 39, 56));

    //start city box
    sf::RectangleShape startCityBox(sf::Vector2f(120.f, 30.f));
    startCityBox.setFillColor(sf::Color(187,140, 187));
    startCityBox.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 55.f);

    //start city input
    sf::Text startCityInput("", fontSub, 20);
    sf::String startCity;
    startCityInput.setPosition(tripBox.getPosition().x + 15.f, tripBox.getPosition().y + 55.f);
    startCityInput.setFillColor(sf::Color::Black);

    //start country box
    sf::RectangleShape startCountryBox(sf::Vector2f(120.f, 30.f));
    startCountryBox.setFillColor(sf::Color(187,140, 187));
    startCountryBox.setPosition(tripBox.getPosition().x + 150.f, tripBox.getPosition().y + 55.f);

    //start country input
    sf::Text startCountryInput("", fontSub, 20);
    sf::String startCountry;
    startCountryInput.setPosition(tripBox.getPosition().x + 155.f, tripBox.getPosition().y + 55.f);
    startCountryInput.setFillColor(sf::Color::Black);


    //destination text
    sf::Text destText("Destination:", fontSub, 30);
    destText.setPosition(tripBox.getPosition().x + 40.f, tripBox.getPosition().y + 100.f);
    destText.setFillColor(sf::Color(25, 39, 56));

    //destination city box
    sf::RectangleShape destInputBox(sf::Vector2f(120.f, 30.f));
    destInputBox.setFillColor(sf::Color(239, 130, 117));
    destInputBox.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 140.f);

    //destination city input
    sf::Text desCityInput("", fontSub, 20);
    sf::String cityDestination;
    desCityInput.setPosition(tripBox.getPosition().x + 15.f, tripBox.getPosition().y + 140.f);
    desCityInput.setFillColor(sf::Color::Black);

    //destination country box
    sf::RectangleShape destCountryBox(sf::Vector2f(120.f, 30.f));
    destCountryBox.setFillColor(sf::Color(239, 130, 117));
    destCountryBox.setPosition(tripBox.getPosition().x + 150.f, tripBox.getPosition().y + 140.f);

    //destination country input
    sf::Text desCountryInput("", fontSub, 20);
    sf::String countryDestination;
    desCountryInput.setPosition(tripBox.getPosition().x + 160.f, tripBox.getPosition().y + 140.f);
    desCountryInput.setFillColor(sf::Color::Black);

    //drive method text
    sf::Text driveText("Driving Method:", fontSub, 30);
    driveText.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 190.f);
    driveText.setFillColor(sf::Color::Black);

    //dijkstra button
    sf::RectangleShape dijkstraButton(sf::Vector2f(120.f, 30.f));
    dijkstraButton.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 230.f);
    dijkstraButton.setFillColor(sf::Color(104, 166, 145));
    sf::Text dijText("Dijkstra", fontHead, 16);
    dijText.setPosition(dijkstraButton.getPosition().x + 30.f, dijkstraButton.getPosition().y + 5.f);
    dijText.setFillColor(sf::Color::White);
    bool runDijkstra = false;


    //prims button
    sf::RectangleShape primsButton(sf::Vector2f(120.f, 30.f));
    primsButton.setPosition(tripBox.getPosition().x + 150.f, tripBox.getPosition().y + 230.f);
    primsButton.setFillColor(sf::Color(104, 166, 145));
    sf::Text primText("Prims", fontHead, 16);
    primText.setPosition(primsButton.getPosition().x + 36.f, primsButton.getPosition().y + 5.f);
    primText.setFillColor(sf::Color::White);
    bool runPrims = false;

    //STEPS
    std::string instuctString = "INSTRUCTIONS:\nOur question for you is: \nWhere in the world do you want to go?\nNo matter where it is, we'll help you get there.\nTo plan your roadtrip successfully, enter your\nstart and destination city in the format\n\n[city name], [state/providence abbrviation],\n\nand just type the country name\nin the country field. Make sure that your trip is\nacross one landmass - we don't know how to\ndrive over water yet! Then, select your path\nmaking algorithm (Dijikstra's or Prim's) and\nwatch your itinerary form.\n\nSave a copy, hit the \"Download Trip!\" button.";
    sf::Text instructions;
    instructions.setFont(fontBody);
    instructions.setString(instuctString);
    instructions.setCharacterSize(12);
    instructions.setFillColor(sf::Color::Black);
    instructions.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 280.f);;

    //start country info
    sf::Text startCountryInfo("--------Start Country Information----------", fontSub, 10);
    startCountryInfo.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 290.f);
    startCountryInfo.setFillColor(sf::Color::Black);

    //end country info
    sf::Text endCountryInfo("--------End Country Information----------", fontSub, 10);
    endCountryInfo.setPosition(tripBox.getPosition().x + 10.f, tripBox.getPosition().y + 290.f);
    endCountryInfo.setFillColor(sf::Color::Black);

    //reset button
    sf::RectangleShape resetButton(sf::Vector2f(120.f, 30.f));
    resetButton.setPosition(tripBox.getPosition().x + 90.f, tripBox.getPosition().y + 600.f);
    resetButton.setFillColor(sf::Color(187,140, 187));
    sf::Text resetText("Reset Trip!", fontHead, 14);
    resetText.setPosition(resetButton.getPosition().x + 21.f, resetButton.getPosition().y + 5.f);
    resetText.setFillColor(sf::Color::White);

    // download button
    sf::RectangleShape downloadButton(sf::Vector2f(120.f, 30.f));
    downloadButton.setPosition(tripBox.getPosition().x + 90.f, 760.f);
    downloadButton.setFillColor(sf::Color(187,140, 187));
    sf::Text downloadText("Download Trip!", fontHead, 14);
    downloadText.setPosition(downloadButton.getPosition().x + 7.f, downloadButton.getPosition().y + 5.f);
    downloadText.setFillColor(sf::Color::White);

    //TEMP window after button click
    sf::RenderWindow drivingWindow(sf::VideoMode(400, 200), "Loading");
    drivingWindow.setVisible(false);

    //user switch between start and destination
    enum State {
        None,
        inputStartCity,
        inputStartCountry,
        inputDesCity,
        inputDesCountry
    };
    State current = None;

    //active editing
    bool editing = false;

    //temp text output
    std::string longtext = "dummy data:\n--------Start Country Information----------\n Country: United States\nRegion: Americas\nCapitol: Washington\nCurrency: United States dollar\nStart City WikiData Information: https://www.wikidata.org/wiki/Q49255\n--------End Country Information----------\nCountry: United States\nRegion: Americas\nCapitol: Washington\nCurrency: United States dollar\nEnd City WikiData Information: https://www.wikidata.org/wiki/Q49255\n********************************************************\n1. Tampa, FL, United States | Distance so far: 0\n2. Hill 'n Dale, FL, United States | Distance so far: 40.6768\n3. Marion County, FL, United States | Distance so far: 90.5566\n4. Interlachen, FL, United States | Distance so far: 120.798\n5. Orange Park, FL, United States | Distance so far: 159.834\n6. Jacksonville, FL, United States | Distance so far: 171.697\nTotal distance travelled: 171.697\n\n1. Tampa, FL, United States | Distance so far: 0\n2. Hill 'n Dale, FL, United States | Distance so far: 40.6768\n3. Marion County, FL, United States | Distance so far: 90.5566\n4. Interlachen, FL, United States | Distance so far: 120.798\n5. Orange Park, FL, United States | Distance so far: 159.834\n6. Jacksonville, FL, United States | Distance so far: 171.697\nTotal distance travelled: 171.697\n\n1. Tampa, FL, United States | Distance so far: 0\n2. Hill 'n Dale, FL, United States | Distance so far: 40.6768\n3. Marion County, FL, United States | Distance so far: 90.5566\n4. Interlachen, FL, United States | Distance so far: 120.798\n5. Orange Park, FL, United States | Distance so far: 159.834\n6. Jacksonville, FL, United States | Distance so far: 171.697\nTotal distance travelled: 171.697\n\n1. Tampa, FL, United States | Distance so far: 0\n2. Hill 'n Dale, FL, United States | Distance so far: 40.6768\n3. Marion County, FL, United States | Distance so far: 90.5566\n4. Interlachen, FL, United States | Distance so far: 120.798\n5. Orange Park, FL, United States | Distance so far: 159.834\n6. Jacksonville, FL, United States | Distance so far: 171.697\nTotal distance travelled: 171.697\n\n1. Tampa, FL, United States | Distance so far: 0\n2. Hill 'n Dale, FL, United States | Distance so far: 40.6768\n3. Marion County, FL, United States | Distance so far: 90.5566\n4. Interlachen, FL, United States | Distance so far: 120.798\n5. Orange Park, FL, United States | Distance so far: 159.834\n6. Jacksonville, FL, United States | Distance so far: 171.697\nTotal distance travelled: 171.697";
    sf::Text longText;
    longText.setFont(fontBody);
    longText.setString(longtext);
    longText.setCharacterSize(16);
    longText.setFillColor(sf::Color::Black);
    longText.setPosition(350.f, 100.f);


    //startCountry output
    std::string startOutput= "start";
    sf::Text startCountryOutput;
    startCountryOutput.setFont(fontBody);
    startCountryOutput.setString(longtext);
    startCountryOutput.setCharacterSize(10);
    startCountryOutput.setFillColor(sf::Color::Black);
    startCountryOutput.setPosition(350.f, 150.f);

    //endCountry output
    std::string endOutput = "end";
    sf::Text endCountryOutput;
    endCountryOutput.setFont(fontBody);
    endCountryOutput.setString(longtext);
    endCountryOutput.setCharacterSize(10);
    endCountryOutput.setFillColor(sf::Color::Black);
    endCountryOutput.setPosition(350.f, 200.f);


    float scrollSpeed = 10.0f;


    //view for scrolling
//    sf::View scrollingView(sf::FloatRect (300.f, 0.f, 800.f, longText.getGlobalBounds().height)); //based on text height

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            //scrolling
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Up){
                    longText.move(0, -scrollSpeed);
                }
                else if(event.key.code == sf::Keyboard::Down) {
                    longText.move(0,scrollSpeed);
                }
            }

            //user input mouse
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

                if (startCityBox.getGlobalBounds().contains(mousePos)) {
                    current = inputStartCity;
                    editing = true;
                } else if (startCountryBox.getGlobalBounds().contains(mousePos)) {
                    current = inputStartCountry;
                    editing = true;
                } else if (destInputBox.getGlobalBounds().contains(mousePos)) {
                    current = inputDesCity;
                    editing = true;
                } else if (destCountryBox.getGlobalBounds().contains(mousePos)) {
                    current = inputDesCountry;
                    editing = true;
                } else {
                    current = None;
                    editing = false;
                }
            }


            //user input
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8) {
                    if (current == inputStartCity && !startCity.isEmpty()) {
                        startCity.erase(startCity.getSize() - 1);
                    } else if (current == inputStartCountry && !startCountry.isEmpty()) {
                        startCountry.erase(startCountry.getSize() - 1);
                    } else if (current == inputDesCity && !cityDestination.isEmpty()) {
                        cityDestination.erase(cityDestination.getSize() - 1);
                    } else if (current == inputDesCountry && !countryDestination.isEmpty()) {
                        countryDestination.erase(countryDestination.getSize() - 1);
                    }
                } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    if (current == inputStartCity) {
                        startCity += static_cast<char>(event.text.unicode);
                    } else if (current == inputStartCountry) {
                        startCountry += static_cast<char>(event.text.unicode);
                    } else if (current == inputDesCity) {
                        cityDestination += static_cast<char>(event.text.unicode);
                    } else if (current == inputDesCountry) {
                        countryDestination += static_cast<char>(event.text.unicode);
                    }
                }
            }

            //input editing
            if(editing) {
                if (sf::milliseconds(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ? 1 : 0).asMilliseconds() > 500) {
                    switch (current) {
                        case inputStartCity:
                            startCityInput.setString(startCity + "|");
                            break;
                        case inputStartCountry:
                            startCountryInput.setString(startCountry + "|");
                            break;
                        case inputDesCity:
                            desCityInput.setString(cityDestination + "|");
                            break;
                        case inputDesCountry:
                            desCountryInput.setString(countryDestination + "|");
                            break;
                        default:
                            break;
                    }
                }
            }
            else {
                switch(current) {
                    case inputStartCity:
                        startCityInput.setString(startCity);
                        break;
                    case inputStartCountry:
                        startCountryInput.setString(startCountry);
                        break;
                    case inputDesCity:
                        desCityInput.setString(cityDestination);
                        break;
                    case inputDesCountry:
                        desCountryInput.setString(countryDestination);
                        break;
                    default:
                        break;
                }
            }

            //driving button clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

                //dijkstra button dijkstraButton.getGlobalBounds().contains(mousePos)
                if (dijkstraButton.getGlobalBounds().contains(mousePos)) {
                    cout << "Dijkstra Trip!" << endl; //call method here
                    std::cout << "Start City: " << startCity.toAnsiString() << std::endl;
                    std::cout << "Start Country: " << startCountry.toAnsiString() << std::endl;
                    std::cout << "Destination City: " << cityDestination.toAnsiString() << std::endl;
                    std::cout << "Destination Country: " << countryDestination.toAnsiString() << std::endl;
                    //itinerary output
                    std::string itinString = "itinerary";
                    sf::Text itinerary;
                    longText.setFont(fontBody);
                    longText.setString(longtext);
                    longText.setCharacterSize(10);
                    longText.setFillColor(sf::Color::Black);
                    longText.setPosition(350.f, 100.f);

                    window.draw(itinerary);
                    window.draw(startCountryOutput);
                    window.draw(endCountryOutput);
                    runDijkstra = true;
                    drivingWindow.setVisible(true);
                }
                    //prims button
                else if (primsButton.getGlobalBounds().contains(mousePos)) {
                    //itinerary output
                    std::string itinString = "itinerary";
                    sf::Text itinerary;
                    longText.setFont(fontBody);
                    longText.setString(longtext);
                    longText.setCharacterSize(10);
                    longText.setFillColor(sf::Color::Black);
                    longText.setPosition(350.f, 100.f);

                    window.draw(itinerary);
                    window.draw(startCountryOutput);
                    window.draw(endCountryOutput);
                    runPrims = true; //when prims clicked on
                    cout << "Prims Trip!" << endl; //call method here
                    drivingWindow.setVisible(true);
                } else if (resetButton.getGlobalBounds().contains(mousePos)) {
                    //resets input fields
                    startCity.clear();
                    startCountry.clear();
                    cityDestination.clear();
                    countryDestination.clear();

                    //starts back at input start city
                    current = inputStartCity;
                    cout << "Trip Reset!" << endl;
                } else if (downloadButton.getGlobalBounds().contains(mousePos)) {
                    //download trip itinerary

                    cout << "Trip Downloaded!" << endl;
                }
            }
        }

        window.clear(sf::Color(210, 180, 140));

        window.draw(background);
        window.draw(logoSprite);
        window.draw(text);

        window.draw(tripBox);
        window.draw(topBar);
        window.draw(pointSprite);
        window.draw(pointSprite2);
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
        window.draw(instructions);

        window.draw(resetButton);
        window.draw(resetText);

        window.draw(downloadButton);
        window.draw(downloadText);
        //scrolling
        window.draw(longText);

        window.display();
    }

    return 0;
}

