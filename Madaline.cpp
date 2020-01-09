#include <bits/stdc++.h>
using namespace std;

float b1, b2, w11, w12, w21, w22, v1, v2, vb;
float activation(float x)
{
    if (x >= 0)
        return 1;
    else
        return -1;
}

float train(float target[])
{
    float a = 0.1;
    float x1[] = {-1, -1, 1, 1};
    float x2[] = {-1, 1, -1, 1};
    //float ntarget[] = {0, 1};
    float zin1, zin2, zout1, zout2, yin, yout;
    v1 = 0.5, v2 = 0.5, vb = 0.5;
    bool epoch[] = {false, false, false, false};
    bool ch;

    cout << "x1\t"
         << "x2\t"
         << "b\t"
         << "t\t"
         << "zin1\t"
         << "zin2\t"
         << "z1\t"
         << "z2\t"
         << "yin\t"
         << "v1\t"
         << "v2\t"
         << "vb\t"
         << "yout\t"
         << "w11\t"
         << "w21\t"
         << "b1\t"
         << "w12\t"
         << "w22\t"
         << "b2\t\n";
    //float target[] = {1, -1, -1, -1};
    do
    {
        for (int i = 0; i < 4; i++)
        {
            zin1 = x1[i] * w11 + x2[i] * w21 + b1;
            zin2 = x1[i] * w12 + x2[i] * w22 + b2;
            zout1 = activation(zin1);
            zout2 = activation(zin2);
            yin = zout1 * v1 + zout2 * v2 + vb;
            yout = activation(yin);
            if (target[i] == yout)
            {
                epoch[i] = true;
            }
            else
            {
                if (target[i] == 1)
                {
                    if (zin1 < zin2)
                    {
                        w11 = w11 + a * (target[i] - zin1) * x1[i];
                        w21 = w21 + a * (target[i] - zin1) * x2[i];
                        b1 = b1 + a * (target[i] - zin1);
                    }
                    else
                    {
                        w12 = w12 + a * (target[i] - zin2) * x1[i];
                        w22 = w22 + a * (target[i] - zin2) * x2[i];
                        b2 = b2 + a * (target[i] - zin2);
                    }
                }
                else
                {
                    if (zin1 >= 0)
                    {
                        w11 = w11 + a * (target[i] - zin1) * x1[i];
                        w21 = w21 + a * (target[i] - zin1) * x2[i];
                        b1 = b1 + a * (target[i] - zin1);
                    }
                    if (zin2 >= 0)
                    {
                        w12 = w12 + a * (target[i] - zin2) * x1[i];
                        w22 = w22 + a * (target[i] - zin2) * x2[i];
                        b2 = b2 + a * (target[i] - zin2);
                    }
                }
            }
            cout.precision(4);
            cout << x1[i] << "\t" << x2[i] << "\t" << 1 << "\t" << target[i] << "\t" << zin1 << "\t" << zin2 << "\t" << zout1 << "\t" << zout2 << "\t" << yin << "\t" << v1 << "\t" << v2 << "\t" << vb << "\t" << yout << "\t" << w11 << "\t" << w21 << "\t" << b1 << "\t" << w12 << "\t" << w22 << "\t" << b2 << "\t\n";
        }
        ch = true;
        for (int j = 0; j < 4; j++)
        {
            if (epoch[j] == false)
                ch = false;
            epoch[j] = false;
        }
        cout << "\n";
    } while (!ch);
    cout << "End w11 w12 b1: " << w11 << " " << w21 << " " << b1 << endl;
    cout << "End w12 w22 b2: " << w12 << " " << w22 << " " << b2 << endl;
}
void ip_op()
{
    float x1, x2, zin1, zin2, zout1, zout2, yin, yout;
    cout << "Enter test Input :";
    cin >> x1 >> x2;
    zin1 = x1 * w11 + x2 * w21 + b1;
    zin2 = x1 * w12 + x2 * w22 + b2;
    zout1 = activation(zin1);
    zout2 = activation(zin2);
    yin = zout1 * v1 + zout2 * v2 + vb;
    yout = activation(yin);
    cout << "expected output is :" << yout;
}

int main()
{

    w11 = w21 = b1 = w12 = w22 = b2 = 0.1;
    int choice;
    float target[4];
    cout << "\t\t\tMADALINE\n\t";
    cout << "Change Input weights?(1 for Yes else No)";
    cin >> choice;
    if (choice == 1)
    {
        cout << "\nw11 =";
        cin >> w11;
        cout << "\nw12 =";
        cin >> w12;
        cout << "\nw21 =";
        cin >> w21;
        cout << "\nw22 =";
        cin >> w22;
        cout << "\nb1 =";
        cin >> b1;
        cout << "\nb2 =";
        cin >> b2;
    }
    cout << "Enter the target array: ";
    for (int i = 0; i < 4; i++)
    {
        cout << "\nInput " << i + 1 << ":";
        cin >> target[i];
    }

    train(target);
    ip_op();
    cout << endl;
    return 0;
}
