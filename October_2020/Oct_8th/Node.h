#ifndef CPP_DAILY_PROBLEMS_NODE_H
#define CPP_DAILY_PROBLEMS_NODE_H

template <typename T>

class Node {
    private:
        T data;
        Node<T> *prev;
    public:
        Node<T>(T data);
        T getData();
        void setPrevious(Node<T> nodeToSet);
        Node<T> getPrevious();
};

#endif //CPP_DAILY_PROBLEMS_NODE_H
