#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include <SFML/System.hpp>


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(550, 550), "SFML works!");

    int w = 98;
    int grid[4][4];
    int sgrid[4][4];

    sf::Texture t1;
    t1.loadFromFile("card.png");
    t2.loadFromFile("table.png");
    
    sf::Sprite s(t1);
    sf::Sprite sbackground(t2);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            sgrid[i][j] = 4;
        }

   

   while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                {
                   if (!isSwap && !isMoving) click++;
                   pos = Mouse::getPosition(app)-offset;
                }
         }

        window.draw(sbackground);
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++) {
                s.setTextureRect(sf::IntRect(sgrid[i][j], sgrid[i][j],w-28, 1360));
                s.setPosition(i * w-18, j * w-10);
                window.draw(s);
            }
        

        window.display();
    }
    return 0;
}
