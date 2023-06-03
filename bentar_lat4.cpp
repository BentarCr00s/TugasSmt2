#include <iostream>
#include <vector>

using namespace std;

void ball_sort(vector<vector<char>> &ball_stack)
{
    int n = ball_stack.size();
    int sorted_balls = 0;

    while (sorted_balls < n * n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!ball_stack[i].empty())
            {
                char top_ball = ball_stack[i].back();

                // Cari stack yang cocok untuk dipindahkan bola
                for (int j = 0; j < n; j++)
                {
                    if (i != j && ball_stack[j].size() < 3)
                    {
                        if (ball_stack[j].empty() || ball_stack[j].back() == top_ball)
                        {
                            ball_stack[j].push_back(top_ball);
                            ball_stack[i].pop_back();
                            sorted_balls++;
                            break;
                        }
                    }
                }
            }
        }
    }

    // Tampilkan stack yang telah diurutkan
    for (int i = 0; i < n; i++)
    {
        for (char ball : ball_stack[i])
        {
            cout << ball << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> ball_stack{
        {'r', 'b', 'b'},
        {'y', 'r', 'b'},
        {'y', 'y', 'r'},
    };

    ball_sort(ball_stack);

    return 0;
}
