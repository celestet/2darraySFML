//sf::RectangleShape** createArray(int rows, int col);
//void fillArray(sf::RectangleShape** p, int row, int col);
//sf::RectangleShape newRectangleShape(int x, int y);
//void deleteArray(sf::RectangleShape** p, int rows);
//void draw(sf::RenderWindow& window, sf::RectangleShape** p, int row, int col);

//create and fill from vid

//down:shrinks = down by one row one col, opposite for up

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


sf::RectangleShape **createArray(int rows, int col);//create 2d array
void fillArray(sf::RectangleShape **p, int row, int col);//adding coordinates to array
sf::RectangleShape newRectangleShape(int x, int y);//new shape
void deleteArray(sf::RectangleShape **p, int rows);//disappear from screen
void draw(sf::RenderWindow &window, sf::RectangleShape **p, int row, int col);//draws to screen


int main() {
    sf::VideoMode video(1920, 1080, 32);
    sf::RenderWindow window(video, "labSFML 2D array");//creating a window




    sf::RectangleShape square = newRectangleShape(0, 0);
    int rows = 1, col = 1;


    sf::RectangleShape **aArray = createArray(1, 1);

    fillArray(aArray, rows, col);

    while (window.isOpen()) {//while the window is open
        sf::Event event;//creates an event
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {//if event stop
                window.close();
            }



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {//should increase rows and columns

                deleteArray(aArray, rows);

                rows++;
                col++;
               aArray = createArray(rows, col);
                fillArray(aArray, rows, col);


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {



                if(rows > 0&& col > 0){
                    deleteArray(aArray, rows);

                    rows--;
                    col--;
                    aArray = createArray(rows, col);
                    fillArray(aArray, rows, col);
                }

            }

        }
        window.clear(sf::Color(125, 0, 125));

        draw(window, aArray, rows, col);

        window.display();


    }
}


sf::RectangleShape **createArray(int rows, int col) {
    sf::RectangleShape **p;//initialize p
    p = new sf::RectangleShape *[rows];//create an array of rows
    for (int i = 0; i < rows; i++) {
        *(p + i) = new sf::RectangleShape[col];//create an array of columns

    }
    return p;
}

void fillArray(sf::RectangleShape **p, int row, int col) {
//    float x, y;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sf::RectangleShape shape = newRectangleShape(10, 10);
            shape.setPosition(i*110, j*110);

            *(*(p + i) + j) = shape;//address of each array = a value

            // aka p[i][j] = count
        }
    }
}


sf::RectangleShape newRectangleShape(int x, int y) {
    sf::RectangleShape square;//create a square
    sf::Vector2f size(100, 100);//width, height
    square.setSize(size);//or square.setsize({100,100})
    square.setFillColor(sf::Color::White);//colored square
    square.setPosition({0, 0});

    return square;
}

void deleteArray(sf::RectangleShape **p, int rows) {
    for (int i = 0; i < rows; i++) {
        delete []*(p+i);

    }
    delete []p;
}

void draw(sf::RenderWindow &window, sf::RectangleShape **p, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            window.draw(*(*(p + i) + j));
        }
    }

}


