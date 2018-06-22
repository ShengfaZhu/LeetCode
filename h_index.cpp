// 274. H-Index
// counting sort
int hIndex(vector<int>& citations) {
    vector<int> count(citations.size()+1, 0);
    for (int cita : citations)
        if (cita < count.size())
            count[cita]++;
        else
            count[count.size()-1]++;
    int h_index = 0, sum = 0;
    for (int i = count.size()-1; i >= 0; i--) {
        sum += count[i];
        if (sum >= i) {
            h_index = i;
            break;
        }
    }
    return h_index;
}