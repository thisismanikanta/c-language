#include<stdio.h>
#include<limits.h>

int findOptimalPage(int pages[], int frames[], int currentIndex, int n, int k) {
    int farthest = currentIndex;
    int indexToReplace = -1;

    for (int i = 0; i < k; i++) {
        int j;
        for (j = currentIndex; j < n; j++) {
            if (frames[i] == pages[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
        if (j > farthest) {
            farthest = j;
            indexToReplace = i;
        }
    }

    return indexToReplace;
}

int getFault(int pages[], int frames[], int n, int k) {
    int count = 0;

    for (int i = 0; i < k; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int avail = 0;
        
        for (int j = 0; j < k; j++) {
            if (frames[j] == pages[i]) {
                avail = 1;
                break;
            }
        }

        if (avail == 0) {
            int replaceIndex = findOptimalPage(pages, frames, i + 1, n, k);
            frames[replaceIndex] = pages[i];
            count++;
        }
    }

    return count;
}

int main() {
    int n, pages[50], frames[50], k;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &k);

    int fault = getFault(pages, frames, n, k);

    printf("Page faults are: %d\n", fault);

    return 0;
}
