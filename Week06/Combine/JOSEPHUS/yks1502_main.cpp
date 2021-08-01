#include <bits/stdc++.h>
using namespace std;

int C, N, K;

class Node {
    public:
        int number;
        Node* next = NULL;
        Node* prev = NULL;
        Node(int number) { this->number = number; }
};

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N >> K;

        Node *head = new Node(1);
        Node *curr = head;

        for (int j = 1; j < N; j++) {
            Node *node = new Node(j + 1);
            curr->next = node;
            node->prev = curr;
            curr = node;
        }
        curr->next = head;
        head->prev = curr;
        curr = head;

        for (int i = 0; i < N - 2; i++) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            for (int j = 0; j < K; j++) {
                curr = curr->next;
            }
        }

        int result1 = curr->number;
        int result2 = curr->next->number;

        cout << min(result1, result2) << " " << max(result1, result2) << endl;
    }
}