struct List_Node {
    int key;
    int val;
    List_Node *prev;
    List_Node *next;
};

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {
        if (capacity <= 0) {
            return;
        }
        begin = new List_Node();
        List_Node *pNow = begin;
        for (int i = 1; i < capacity; ++i) {
            pNow->next = new List_Node();
            pNow->next->prev = pNow;
            pNow = pNow->next;
        }
        end = pNow;
        begin->prev= NULL;
        end->next = NULL;
    }
    
    int get(int key) {
        if (kRec.find(key) == kRec.end()) {
            return -1;
        }
        else{
            List_Node *ret = kRec[key];
            if (cap == 1){
                return ret->val;
            }
            if (ret == begin) {
                return ret->val;
            }
            ret->prev->next = ret->next;
            if (ret != end) {
                ret->next->prev = ret->prev;
            }
            else{
                end = ret->prev;
            }
            begin->prev = ret;
            ret->next = begin;
            ret->prev = NULL;
            begin = ret;
            return ret->val;
        }
    }
    
    void put(int key, int value) {
        if (kRec.find(key) != kRec.end()) {
            List_Node *ins = kRec[key];          
            ins->val = value;   
            if (cap == 1 || ins == begin){
                return;
            }
            ins->prev->next = ins->next;
            if (ins != end) {
                ins->next->prev = ins->prev;
            }
            else{
                end = ins->prev;
            }
            ins->next = begin;
            begin->prev = ins;
            ins->prev = NULL;
            begin = ins;
        }
        else{
            List_Node *ins = end;
            if (kRec.find(end->key) != kRec.end()) {
                kRec.erase(kRec.find(end->key));
            }              
            ins->val = value;
            ins->key = key;      
            kRec.insert(pair<int, List_Node *>(key, ins));
            if (cap == 1){
                return;
            }
            end->prev->next = NULL;
            end = end->prev;
            ins->next = begin;
            begin->prev = ins;
            ins->prev = NULL;
            begin = ins;
        }
    }

private:
    int cap;
    List_Node *begin, *end;
    unordered_map<int, List_Node *> kRec; 
};
