// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n) {
        struct Process {
            int arrival;
            int burst;
            int index;
            bool completed = false;
            int completionTime = 0;
            int turnAroundTime = 0;
            int waitingTime = 0;
        };

        vector<Process> processes(n);
        for (int i = 0; i < n; ++i) {
            processes[i] = {arrivalTime[i], burstTime[i], i};
        }

        int currentTime = 0, completed = 0;
        double totalWT = 0, totalTAT = 0;

        while (completed < n) {
            int idx = -1;
            int minBurst = INT_MAX;

            for (int i = 0; i < n; ++i) {
                if (!processes[i].completed && processes[i].arrival <= currentTime) {
                    if (processes[i].burst < minBurst || 
                        (processes[i].burst == minBurst && processes[i].arrival < processes[idx].arrival)) {
                        minBurst = processes[i].burst;
                        idx = i;
                    }
                }
            }

            if (idx != -1) {
                currentTime += processes[idx].burst;
                processes[idx].completionTime = currentTime;
                processes[idx].turnAroundTime = processes[idx].completionTime - processes[idx].arrival;
                processes[idx].waitingTime = processes[idx].turnAroundTime - processes[idx].burst;

                totalWT += processes[idx].waitingTime;
                totalTAT += processes[idx].turnAroundTime;

                processes[idx].completed = true;
                completed++;
            } else {
                currentTime++;  // No process is ready, move time forward
            }
        }

        return {totalWT / n, totalTAT / n};
    }
};
