/**
 * Ceiling Function
 * 12767
 */
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
struct Node{
  int val;
  Node *left;
  Node *right;
  Node(){
    val = 0;
    left = NULL;
    right = NULL;
  }
};
void remove(Node* root){
  if(root->left){
    remove(root->left);
  }
  if(root->right){
    remove(root->right);
  }
  delete root;
}
string preorder(Node* root){
  string ans = "V";
  if(root->left){
    ans += 'L';
    ans += preorder(root->left);
    ans += 'l';
  }
  if(root->right){
    ans += 'R';
    ans += preorder(root->right);
    ans += 'r';
  }
  ans += 'v';
  return ans;
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n,k;
  cin>>n>>k;
  set<string> s;
  while(n--){
    vector<int> a(k);
    for(int i=0;i<k;i++){
      cin>>a[i];
    }
    Node* root = new Node;
    root->val = a[0];
    root->left = NULL;
    root->right = NULL;
    for(int i=1;i<k;i++){
      Node* cur = root;
      while(true){
        if(cur->val < a[i]){
          if(cur->right == NULL){
            cur->right = new Node;
            cur->right->val = a[i];
            break;
          }
          else{
            cur = cur->right;
          }
        }
        else if(cur->val > a[i]){
          if(cur->left == NULL){
            cur->left = new Node;
            cur->left->val = a[i];
            break;
          }
          else{
            cur = cur->left;
          }
        }
        else break;
      }
    }
    s.insert(preorder(root));
    remove(root);
  }
  cout<<s.size()<<'\n';
  return 0;
}
