// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);

    queue<Node *> que;
    if (root)
        que.push(root);
    while (!que.empty())
    {
        // 1. ber kore ana
        Node *f = que.front();
        que.pop();

        // 2. kaaj
        int L, R;
        cin >> L >> R;
        Node *left;
        Node *right;

        if (L == -1)
            left = NULL;
        else
            left = new Node(L);

        if (R == -1)
            right = NULL;
        else
            right = new Node(R);

        f->left = left;
        f->right = right;

        // 3. children pusk kora
        if (f->left)
            que.push(f->left);
        if (f->right)
            que.push(f->right);
    }

    return root;
}
vector<int> level_order(Node *root)
{
    vector<int> ans;
    // if (root == NULL)
    // {
    //     return {};
    // }
    queue<Node *> que;
    if (root)
        que.push(root);
    while (!que.empty())
    {
        // 1. ber kore ana
        Node *f = que.front();
        que.pop();

        // 2. Front er value diye jaa kaaj ase shob ekhane korte hobe
        // cout << f->value << " ";
        ans.push_back(f->value);

        // 3. Tar Child der que te rakha
        if (f->left)
            que.push(f->left);
        if (f->right)
            que.push(f->right);
    }
    return ans;
}

int main()
{
    Node *root = input_tree();
    // vector<int> ans;
    vector<int> res = level_order(root);

    reverse(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    // for (int i = res.size() - 1; i >= 0; i--)
    // {
    //     ans.push_back(res[i]);
    // }

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    return 0;
}

/*
input
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

output
7 6 5 4 3 2 1
*/