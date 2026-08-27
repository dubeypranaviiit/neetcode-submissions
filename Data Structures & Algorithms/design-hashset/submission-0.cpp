class MyHashSet {
public:
    vector<int> arr;

    MyHashSet() {
    }

    void add(int key) {
  
        if (!contains(key)) {
            arr.push_back(key);
        }
    }

    void remove(int key) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == key) {
              
                for (int j = i; j < arr.size() - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                arr.pop_back();
                return;
            }
        }
    }

    bool contains(int key) {
        for (int x : arr) {
            if (x == key)
                return true;
        }
        return false;
    }
};