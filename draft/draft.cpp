#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

struct Student {
    string id;
    int score;
    int location_number;
    int local_rank;
};

void exchange(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool cmp(Student a, Student b){
    if(a.score!=b.score){
        return b.score<a.score; //a的分数大的时候，a排前面。
    }else{
        return a.id<b.id;       //a的id小的时候，a排前面。
    }
}

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()){
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[0]);
        vector<int> preL;
        vector<int> preR;
        vector<int> vinL;
        vector<int> vinR;
        int len = pre.size();
        int i = 0;
        for(;i<len;i++){
            if(vin[i]==pre[0])
                break;
        }
        for(int j=0;j<i;){
            vinL.push_back(vin[j]);
            j++;
            preL.push_back(pre[j]);
        }
        for(int k=i+1;k<len;k++){
            vinR.push_back(vin[k]);
            preR.push_back(pre[k]);
        }
        root->left = reConstructBinaryTree(preL, vinL);
        root->right = reConstructBinaryTree(preR, vinR);
        return root;
    }

    int index(string str)
    {
        int len = str.size();
        vector<int> log;
        int result = 0;
        int count = 0;
        while (count < len)
        {
            log.push_back(str[count] - 'a');
            count ++;
        }
        if (len == 1)
        {
            result = log[0] * 16276;
        }
        else if (len == 2)
        {
            result = log[0]* 16276 + log[1]*651 + 1;
        }
        else if (len == 3)
        {
            result = log[0]* 16276 + log[1] * 651 + log[2];
        }
        else
        {
            result = log[0] * 16276 + log[1] * 625 + log[2] * 25 + log[3];
        }
        return result;
    }

    ListNode* ReverseList(ListNode* pHead) {
        vector<int> temp;
        ListNode *head = pHead;
        while(head!=NULL){
            temp.push_back(head->val);
            head = head ->next;
        }
        decltype(temp.size()) len = temp.size();
        ListNode *newHead = new ListNode(temp[len-1]);
        for(int i=len-2;i>-1;i--){
            newHead->next = new ListNode(temp[i]);
        }
        return newHead;
    }

    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        int mid = 0;
        while(lo < hi - 1){
            mid = lo + (hi - lo)/2;
            if(nums[mid]<target){
                lo = mid+1;
            }else{
                hi = mid+1;
            }
        }
        if(hi-lo==1&&nums[lo]==target){
            return lo;
        }
        return -1;
    }

    void ranking()
    {
        vector<Student> stu;
        int n, k, num = 0;
        scanf("%d", &n);                                  //输入考场数量
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &k);                              //第i个考场的人数
            for (int j = 0; j < k; j++)
            {
                Student stud;
                stud.location_number = i;
                stud.local_rank = 0;
                stud.id.resize(13);
                scanf("%s %d", &stud.id[0], &stud.score);
                stu.push_back(stud);
                num++;                                    //录入每个考生的信息，更新总考生数
            }
            sort(stu.begin() + num - k, stu.begin() + num, cmp);  //考场内按分数排序
            stu[num - k].local_rank = 1;
            for (int j = num - k + 1; j < num; j++)
            {
                if (stu[j].score == stu[j - 1].score)
                {
                    stu[j].local_rank = stu[j - 1].local_rank;
                }
                else
                {
                    stu[j].local_rank = j + 1 - (num - k);
                }
            }
        }
        printf("%d\n", num);
        sort(stu.begin(), stu.end(), cmp);
        int r = 1;
        for (int i = 0; i < num; i++)
        {
            if (i > 0 && stu[i].score != stu[i - 1].score)
            {
                r = i + 1;
            }
            printf("%s ", stu[i].id.c_str());
            printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
        }
    }
};

int main(){

    return 0;
}
