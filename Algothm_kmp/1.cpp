// Алгоритм KMP
// нужно найти все вхождения Стринга S в строке T
#include <iostream>
#include <vector>

using namespace std;

string s, t;
int main() {
    cin >> s >> t;
    int p = 31;

    
    int maxim = max(s.size(), t.size());
    vector <long long> p_pow(maxim);  // вектор для хранения всех степенй 31
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++) {    // цикл который добавляет все степени
        p_pow[i] = p_pow[i - 1] * p;
    }


    long long h_s = 0;
    for (int i = 0; i < s.size(); i++) {   // цикл который считает хэш подстроки S
        h_s += (s[i] - 'a' + 1) * p_pow[i];
    }

    vector <long long> h(t.size());    
    for (int i = 0; i < t.size(); i++) {   // цикл который считает хэш всей большой строки T
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if (i) { // если это не нулевой элемент то мы его добавляем
            h[i] += h[i - 1];
        }
    } /// короче говоря мы посчитали наш хэш строки T
    
    for (int i = 0; i + s.size() - 1 < t.size(); i++) { // цикл который будет пробегаться и сравнивать подстроку 
        long long cur_h = h[i + s.size() - 1];   // текущая строка 
        if (i) {
            cur_h -= h[i-1];
        }
        if (cur_h == h_s * p_pow[i]) { // подстрока S входит в строку t в позиции i
             cout << i << " ";
        }
    } 
    return 0;
}
// abc
// testabccasabc
// 4 10