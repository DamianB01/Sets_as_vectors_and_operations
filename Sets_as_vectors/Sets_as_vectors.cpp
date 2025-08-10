#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

void sort_insertion(vector<char>& a) {
    for (int i = 1; i < a.size(); i++) {
        auto value = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > value) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
}

void writing(const vector<char>& a, string name) {
    cout << "Set " << name << ": {";
    for (auto i : a) cout << (int)i << ", ";
    cout << "}" << endl;
}

void repeats(vector<char>& a) {
    auto wektor = vector<char>{};
    for (auto x : a) {
        bool is_there = false;
        for (auto y : wektor) {
            if (x == y) {
                is_there = true;
                break;
            }
        }
        if (!is_there) wektor.push_back(x);
    }
    sort_insertion(wektor);
    a = wektor;
}

vector<char> sum_sets(const vector<char>& a, const vector<char>& b) {
    auto sum = a;
    for (auto x : b) {
        bool is_there = false;
        for (auto y : sum) {
            if (x == y) {
                is_there = true;
                break;
            }
        }
        if (!is_there) sum.push_back(x);
    }
    sort_insertion(sum);
    return sum;
}

vector<char> sum_sets(const vector<char>& a, const vector<char>& b, const vector<char>& c) {
    return sum_sets(sum_sets(a, b), c);
}

vector<char> diff_sets(const vector<char>& a, const vector<char>& b) {
    auto sum = vector<char>{};
    for (auto x : a) {
        bool is_there = false;
        for (auto y : b) {
            if (x == y) {
                is_there = true;
                break;
            }
        }
        if (!is_there) sum.push_back(x);
    }
    sort_insertion(sum);
    return sum;
}

vector<char> diff_sets(const vector<char>& a, const vector<char>& b, const vector<char>& c) {
    auto sum = sum_sets(a, b);
    return diff_sets(c, sum);
}

vector<char> common(const vector<char>& a, const vector<char>& b) {
    auto comm = vector<char>{};
    for (auto x : a) {
        bool is_there = false;
        for (auto y : b) {
            if (x == y) {
                is_there = true;
                break;
            }
        }
        if (is_there) comm.push_back(x);
    }
    sort_insertion(comm);
    return comm;
}

vector<char> common(const vector<char>& a, const vector<char>& b, const vector<char>& c) {
    return common(common(a, b), c);
}

vector<char> generate(int n) {
    vector<char> res;
    for (int i = 0; i < n; i++) {
        int num = rand() % 10 + 1;
        res.push_back(num);
    }
    return res;
}

vector<char> generater_letters(int n) {
    vector<char> res;
    for (int i = 0; i < n; i++) {
        char let = 'a' + rand() % 26;
        res.push_back(let);
    }
    return res;
}

void letter_writing(const vector<char>& a, string name) {
    cout << "Set " << name << ": {";
    for (auto i : a) cout << i << ", ";
    cout << "}" << endl;
}

int main()
{
    srand(time(NULL));
    int n;
    vector<char> v1, v2, v3;
    cout << "Enter the size of set v1: ";
    cin >> n;
    v1 = generate(n);
    cout << "Enter the size of set v2: ";
    cin >> n;
    v2 = generate(n);
    cout << "Enter the size of set v3: ";
    cin >> n;
    v3 = generate(n);
    writing(v1, "v1");
    writing(v2, "v2");
    writing(v3, "v3");
    repeats(v1);
    repeats(v2);
    repeats(v3);
    writing(v1, "v1 (no duplicates and sorted)");
    writing(v2, "v2 (no duplicates and sorted)");
    writing(v3, "v3 (no duplicates and sorted)");
    auto sum_of_two = sum_sets(v1, v2);
    auto sum_of_three = sum_sets(v1, v2, v3);
    auto diff_of_two = diff_sets(v1, v2);
    auto diff_of_three = diff_sets(v1, v2, v3);
    auto common_two = common(v1, v2);
    auto common_three = common(v1, v2, v3);
    writing(sum_of_two, "total sum of v1+v2");
    writing(sum_of_three, "total sum of v1+v2+v3");
    writing(diff_of_two, "difference of v1-v2");
    writing(diff_of_three, "difference of v3-(v1+v2)");
    writing(common_two, "common part of v1 and v2");
    writing(common_three, "common part of v1, v2 and v3");
    return 0;
}
