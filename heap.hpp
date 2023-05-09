#include <vector>
#include <cassert>
#include <iostream>

struct Pair
{
    int v, l;

    Pair(int _v, int _l) :
        v(_v), l(_l)
    {}

    Pair()
    {
        v = l = 0;
    }
};


class Heap
{
private:
    std::vector<Pair> data;

private:
    void ify(int i) {
        int left = 2 * i + 1,
            right = 2 * i + 2;

        if (left < data.size()) {
            if (data[i].l < data[left].l) {
                Pair temp = data[i];
                data[i] = data[left];
                data[left] = temp;
                ify(left);
            }
        }

        if (right < data.size()) {
            if (data[i].l < data[right].l) {
                Pair temp = data[i];
                data[i] = data[right];
                data[right] = temp;
                ify(right);
            }
        }
    }

public:
    void add(Pair e)
    {
        int i = data.size(),
            parent = (data.size() - 1) / 2;
        data.push_back(e);

        while (parent >= 0 && i > 0)
        {
            if (data[i].l < data[parent].l)
            {
                Pair temp = data[i];
                data[i] = data[parent];
                data[parent] = temp;
            }
            else
                break;
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    Pair getMin()
    {
        assert(data.size());
        Pair x = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();
        ify(0);
        return x;
    }

    int getSize()
    {
        return data.size();
    }
};
