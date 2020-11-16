#ifndef _LRU_H_
#define _LRU_H_

#include <list>
#include <string>
using namespace std;

class lru_cache {
    list<pair<string, int>> _cache;
    int cap;
public:
    int get(string key) {
        int pos = -1;
        pair<string, int> tmp = make_pair("", 0);
        for (auto iter = _cache.begin(); iter != _cache.end(); iter++) {
            if (iter->first.compare(key) == 0) {
                tmp.first = iter->first;
                tmp.second = iter->second;
                pos = iter - _cache.begin();
                break;
            }
        }
        if (pos >= 0) {
            _cache.erase(_cache.begin() + pos);
            _cache.push_front(tmp);
        } else {
            return -1;
        }
    }

    void put(string key, int value) {
        // found
        int pos = -1;
        pair<string, int> tmp = make_pair("", 0);
        for (auto iter = _cache.begin(); iter != _cache.end(); iter++) {
            if (iter->first.compare(key) == 0) {
                tmp.first = iter->first;
                pos = iter - _cache.begin();
                break;
            }
        }
        if (pos >= 0) {
            _cache.erase(_cache.begin() + pos);
            tmp.second = key;
            _cache.push_front(tmp);
            return;
        } 
        // not found
        if (_cache.size() == this._cap) {
            _cache.pop_back();
        }
        _cache.push_front(make_pair(key, value));
    }
};

#endif