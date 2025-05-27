#include <iostream>
#include <string>
using namespace std;
struct PrintJob {
    int jobID;
    string documentName;
    int pages;
};

class PrintQueue {
private:
    PrintJob jobs[50];
    int front, rear, count;

public:
    PrintQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    void add(PrintJob job) {
        if (count < 50) {
            rear++;
            jobs[rear] = job;
            count++;
        }
    }

    PrintJob remove() {
        if (!isEmpty()) {
            PrintJob job = jobs[front];
            front++;
            count--;
            return job;
        }
        PrintJob empty = {0, "", 0};
        return empty;
    }

    int size() {
        return count;
    }
};

int main() {
    PrintQueue normalQueue;
    PrintQueue fastQueue;

    PrintJob jobs[6] = {
        {1, "Report.pdf", 15},
        {2, "Photo.jpg", 1},
        {3, "Manual.pdf", 25},
        {4, "Note.txt", 2},
        {5, "Book.pdf", 30},
        {6, "Card.pdf", 1}
    };

    cout << "=== Adding Print Jobs ===" << endl;

    for (int i = 0; i < 6; i++) {
        if (jobs[i].pages < 3) {
            fastQueue.add(jobs[i]);
            cout << "Fast Queue: " << jobs[i].documentName << " (" << jobs[i].pages << " pages)" << endl;
        } else {
            normalQueue.add(jobs[i]);
            cout << "Normal Queue: " << jobs[i].documentName << " (" << jobs[i].pages << " pages)" << endl;
        }
    }

    cout << endl << "=== Processing Jobs ===" << endl;

    int totalPages = 0;
    int totalJobs = 0;
    int totalTime = 0;


    while (!fastQueue.isEmpty()) {
        PrintJob job = fastQueue.remove();
        totalJobs++;
        totalPages += job.pages;
        totalTime += job.pages;

        cout << "Processing: " << job.documentName << " (" << job.pages << " pages, " << job.pages << " seconds)" << endl;
    }
    while (!normalQueue.isEmpty()) {
        PrintJob job = normalQueue.remove();
        totalJobs++;
        totalPages += job.pages;
        totalTime += job.pages;

        cout << "Processing: " << job.documentName << " (" << job.pages << " pages, " << job.pages << " seconds)" << endl;
    }
    cout << endl << "=== Results ===" << endl;
    cout << "Total jobs: " << totalJobs << endl;
    cout << "Total pages: " << totalPages << endl;
    cout << "Average pages per job: " << totalPages / totalJobs << endl;
    cout << "Total time: " << totalTime << " seconds" << endl;

    cout << endl << "Add more jobs? Enter name and pages (or 'exit' to stop):" << endl;

    string name;
    int pages;
    int newJobID = 7;

    while (true) {
        cout << "Job name: ";
        cin >> name;

        if (name == "exit") {
            break;
        }

        cout << "Pages: ";
        cin >> pages;

        PrintJob newJob = {newJobID, name, pages};
        newJobID++;

        if (pages < 3) {
            fastQueue.add(newJob);
            cout << "Added to fast queue!" << endl;
        } else {
            normalQueue.add(newJob);
            cout << "Added to normal queue!" << endl;
        }
    }

    if (!fastQueue.isEmpty() || !normalQueue.isEmpty()) {
        cout << endl << "Processing new jobs..." << endl;

        while (!fastQueue.isEmpty()) {
            PrintJob job = fastQueue.remove();
            totalJobs++;
            totalPages += job.pages;
            totalTime += job.pages;
            cout << "Processing: " << job.documentName << " (" << job.pages << " pages)" << endl;
        }

        while (!normalQueue.isEmpty()) {
            PrintJob job = normalQueue.remove();
            totalJobs++;
            totalPages += job.pages;
            totalTime += job.pages;
            cout << "Processing: " << job.documentName << " (" << job.pages << " pages)" << endl;
        }

        cout << endl << "=== Final Results ===" << endl;
        cout << "Total jobs: " << totalJobs << endl;
        cout << "Total pages: " << totalPages << endl;
        cout << "Average pages per job: " << totalPages / totalJobs << endl;
        cout << "Total time: " << totalTime << " seconds" << endl;
    }

    cout << "All done!" << endl;

    return 0;
}
