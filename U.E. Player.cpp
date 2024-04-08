// U.E. Player.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
using namespace std;

class Player
{
private:
   string playerName;
   int playerScore;
public:
    void setPlayerName(string name)
    {
        playerName = name;
    }
    string getPlayerName()
    {
        return playerName;
    }
    void setPlayerScore(int score)
    {
        playerScore = score;
    }
    int getPlayerScore()
    {
        return playerScore;
    }
   Player(string _playerName, int _playerScore) :playerName(_playerName), playerScore(_playerScore)
    {
        setPlayerName(_playerName);
        setPlayerScore(_playerScore);
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    int size=0;
    int PlayerScore = 0;
    string PlayerName = "";
    do
    {
        cout << "\n Укажите количество игроков. ";
        cin >> size;
    } while (size <= 0);
    Player** player = new Player*[size];
    //Если есть конструктор по умолчанию
    //Player* player = new Player[size];
    for (int i = 0; i < size; i++)
    {
        cout << "\n Укажите имя игрока. ";
        cin >> PlayerName;
        do
        {
            cout << "\n Укажите количество очков у игрока. ";
            cin >> PlayerScore;
        } while (PlayerScore < 0);
    //    player[i].setPlayerName(PlayerName);
    //    player[i].setPlayerScore(PlayerScore);
        player[i] = new Player(PlayerName, PlayerScore);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j>i; j--)
        {
            if (player[j]->getPlayerScore() > player[j-1]->getPlayerScore())
            {
                int s=0;
                string n="";
                Player* pl = new Player(n, s);              
                *pl = *player[j];
               * player[j] = *player[j - 1];
                *player[j - 1] = *pl;
                delete pl;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << "\n" << player[i]->getPlayerName() << " " << player[i]->getPlayerScore(); 
        delete player[i];
    }
    delete[] player;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
