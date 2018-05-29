// There are N gas stations along a circular route, where the 
// amount of gas at station i is gas[i].
// You have a car with an unlimited gas tank and it costs 
// cost[i] of gas to travel from station i to its next station (i+1). 
// You begin the journey with an empty tank at one of the gas stations.
// Return the starting gas station's index if you can travel around the 
// circuit once in the clockwise direction, otherwise return -1.
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int i = 0;
    while (i < gas.size()) {
        int curr_gas = 0;
        bool flag = false;
        curr_gas = curr_gas + gas[i] -cost[i];
        if (curr_gas < 0) {
            i++;
            continue;
        } 
        int j = (i + 1) % gas.size();
        while (j != i) {
            curr_gas = curr_gas + gas[j] -cost[j];
            if (curr_gas < 0) {
                flag = true;
                break;
            }
            j = (j + 1) % gas.size();
        }
        if (flag == false) return i;
        else{
            if (j < i) return -1;
            else i = j;
        }
    }
    return -1;
}