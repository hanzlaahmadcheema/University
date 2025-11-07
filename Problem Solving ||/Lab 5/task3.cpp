// Doubly Linked List Problems

// 3. Undo-Redo Functionality in Text Editor
// Scenario: A text editor uses doubly linked list to implement undo-redo functionality. Each node represents a document state.
// Problem: Implement:
//     • Save document state after each operation
//     • Undo (move backward in list)
//     • Redo (move forward in list)
//     • Clear redo stack when new operation is performed after undo
//     • Limit history size to prevent memory issues
#include <iostream>
#include <string>
using namespace std;
struct DocumentState {
    string content;
    DocumentState* prev;
    DocumentState* next;

    DocumentState(const string& c) : content(c), prev(nullptr), next(nullptr) {}
};
class TextEditor {
private:
    DocumentState* current;
    int historySize;
    const int maxHistorySize;
public:
    TextEditor(int maxSize) : current(nullptr), historySize(0), maxHistorySize(maxSize) {}
    ~TextEditor() {
        while (current && current->prev) {
            current = current->prev;
        }
        while (current) {
            DocumentState* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void saveState(const string& content) {
        DocumentState* newState = new DocumentState(content);
        if (current) {
            // Clear redo history
            while (current->next) {
                DocumentState* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            newState->prev = current;
            current->next = newState;
        }
        current = newState;
        historySize++;
        // Limit history size
        if (historySize > maxHistorySize) {
            DocumentState* temp = current;
            while (temp->prev && temp->prev->prev) {
                temp = temp->prev;
            }
            DocumentState* toDelete = temp->prev;
            temp->prev = nullptr;
            delete toDelete;
            historySize--;
        }
    }
    void undo() {
        if (current && current->prev) {
            current = current->prev;
        } else {
            cout << "No more undo steps available." << endl;
        }
    }
    void redo() {
        if (current && current->next) {
            current = current->next;
        } else {
            cout << "No more redo steps available." << endl;
        }
    }
    string getCurrentContent() const {
        return current ? current->content : "";
    }
};
// Example usage
int main() {
    TextEditor editor(5); // Limit history size to 5 states
    editor.saveState("State 1");
    editor.saveState("State 2");
    editor.saveState("State 3");
    cout << "Current Content: " << editor.getCurrentContent() << endl; // State 3
    editor.undo();
    cout << "After Undo: " << editor.getCurrentContent() << endl; // State 2
    editor.redo();
    cout << "After Redo: " << editor.getCurrentContent() << endl; // State 3
    editor.saveState("State 4");
    cout << "After New Save: " << editor.getCurrentContent() << endl; // State 4
    editor.undo();
    editor.undo();
    cout << "After Two Undos: " << editor.getCurrentContent() << endl;  // State 2
    return 0;
}