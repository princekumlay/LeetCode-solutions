class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        //if list is empty or contains up to three nodes
        if(!head || !head->next || !head->next->next){
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;//comparision starts from 1st node with prev and next

        int firstCritical = -1;
        int prevCritical = -1;//it always points to the previous critical
        int minDistance = INT_MAX;

        while(curr->next != nullptr){
            bool localMaxima = (curr->val > prev->val) && (curr->val > curr->next->val);
            bool localMinima = (curr->val < prev->val) && (curr->val < curr->next->val);

            if(localMaxima || localMinima){
                if(firstCritical == -1){
                    firstCritical = index;
                }
                else{
                    minDistance = min(minDistance, index - prevCritical);
                }
                prevCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        //if only one critical point is found
        if(firstCritical == -1 || prevCritical == firstCritical){
            return {-1, -1};
        }

        return {minDistance, prevCritical - firstCritical};
    }
};