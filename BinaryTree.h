#pragma once
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<unordered_map>
#include<queue>
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode():val(0),left(nullptr),right(nullptr){;}
    TreeNode(int val):val(val),left(nullptr),right(nullptr){;}
};

class BinaryTree{
private:
    TreeNode*root_;
    int size_;
public:
    BinaryTree():size_(0){;}
    BinaryTree(int val):size_(0){CreatRoot(val);}
    //从序列化构造树
    BinaryTree(std::string data):size_(0){StringtoTree(data);}
    //从前中序遍历构造树
    BinaryTree(std::vector<int>preorder,std::vector<int>midorder):size_(preorder.size()){root_=buildTree(preorder,midorder);}
    ~BinaryTree(){remove(root_);}
public:
    //序列化树
    std::string TreetoString(){return deserialize(root_);}
    std::string TreetoString(TreeNode*node){return deserialize(node);}
    //反序列化树（建树）
    void StringtoTree(std::string data){root_=deserialize(data);}
    TreeNode*StringtoTree_val(std::string data){return deserialize(data);}
private:
    //根节点
    void CreatRoot(int val){
        if(root_==nullptr)root_=new TreeNode(val);
        else root_->val=val;
        size_=1;
    }
    TreeNode*buildTree_(std::vector<int>pre,int l1,int r1,std::vector<int>in,int l2,int r2,std::unordered_map<int,int>map){
        if(l1>r1)return nullptr;
        TreeNode*head=new TreeNode(pre[l1]);
        if(l1==r1)return head;
        int find=map.find(pre[l1])->second;
        head->left=buildTree_(pre,l1+1,l1+find-l2,in,l2,find-1,map);
        head->right=buildTree_(pre,l1+find-l2+1,r1,in,find+1,r2,map);
        return head;
    }
public:
    //从中序和先序建立二叉树
    TreeNode*buildTree(std::vector<int>preorder,std::vector<int>midorder){
        if(preorder.empty()||midorder.empty()||preorder.size()!=midorder.size())return nullptr;
        std::unordered_map<int,int>map;
        for(int i=0;i<midorder.size();i++)map[midorder[i]]=i;
        return buildTree_(preorder,0,preorder.size()-1,midorder,0,midorder.size()-1,map);
    }
public:
    //左结点
    bool Insert_left(TreeNode*node,int val){
        if(node==nullptr){
            if(size_==0)return false;//数中结点个数为0，且此节点不为空，异常
            else root_=new TreeNode(val);//否则当前结点为空，且结点个数不为0，根节点未建立
        }else{
            if(node->left!=nullptr)return false;//此节点已存在
            else node->left=new TreeNode(val);
        }
        size_++;
        return true;
    }
    //右结点
    bool Insert_right(TreeNode*node,int val){
        if(node==nullptr){
            if(size_==0)return false;//数中结点个数为0，且此节点不为空，异常
            else root_=new TreeNode(val);//否则当前结点为空，且结点个数不为0，根节点未建立
        }else{
            if(node->right!=nullptr)return false;//此节点已存在
            else node->right=new TreeNode(val);
        }
        size_++;
        return true;
    }
    //删除以node为根节点的结点及其子树
    bool remove(TreeNode*&node){
        if(node==nullptr)return true;
        if(remove(node->left)&&remove(node->right)){
            delete node;
            node=nullptr;
            size_--;
            return true;
        }else return false;
    }
public:
    //获得头结点
    TreeNode*Root(){return root_;}
    //获得结点上的值
    int Val(TreeNode*node){return node->val;}
    //获得左结点
    TreeNode*Left(TreeNode*node){return node->left;}
    //获得右结点
    TreeNode*Right(TreeNode*node){return node->right;}
    //获得子树结点个数
    int Size(){return size_;}
private:
    //将反序列化的树转化为树
    TreeNode*redeserialize(std::list<std::string>&Arrardata){
        if(Arrardata.front()=="#"){
            Arrardata.erase(Arrardata.begin());
            return nullptr;
        }
        TreeNode*root=new TreeNode(std::stoi(Arrardata.front()));
        Arrardata.erase(Arrardata.begin());
        root->left=redeserialize(Arrardata);
        root->right=redeserialize(Arrardata);
        return root;
    }
    TreeNode*deserialize(std::string data){
        std::list<std::string> Arraydata;
        std::string str;
        for(char&ch:data){
            if(ch==','){
                Arraydata.push_back(str);
                size_++;
                str.clear();
            }else{
                str.push_back(ch);
            }
        }
        //str里剩下的也放进去
        if(!str.empty()){
            Arraydata.push_back(str);
            size_++;
            str.clear();
        }
        return redeserialize(Arraydata);
    }
private:
    /*将树序列化*/
    void redeserialize(TreeNode*root,std::string&data){
        if(root==nullptr)data+="#,";
        else{
            data+=std::to_string(root->val)+",";
            redeserialize(root->left,data);
            redeserialize(root->right,data);
        }
    }
    //反序列化
    std::string deserialize(TreeNode*root){
        std::string data;
        redeserialize(root,data);
        return data;
    }
public:
    int GetMinLen(){return MinLen(root_);}
    int GetMinLen(TreeNode*node){return MinLen(node);}
    int GetMaxLen(){return MaxLen(root_);}
    int GetMaxLen(TreeNode*node){return MaxLen(node);}
    //判断树是否平衡
    bool Isbanace(){return Banace(root_);}
    bool Isbanace(TreeNode*node){return Banace(node); }
private:
    int MinLen(TreeNode*node){
        if(node==nullptr)return 0;
        if(!node->left||!node->right)return MinLen(node->left)+MinLen(node->right)+1;
        else return std::min(MinLen(node->left),MinLen(node->right))+1;
    }
    int MaxLen(TreeNode*node){
        if(node==nullptr)return 0;
        return std::max(MaxLen(node->left),MaxLen(node->right))+1;
    }
    bool Banace(TreeNode*node){
        if(node==nullptr)return true;
        bool ans=Banace(node->left)&&Banace(node->right);
        if(abs(MaxLen(node->left)-MaxLen(node->right))>1)return false;
        return ans;
    }
private:
    //判断是否为完全二叉树
    bool isCompleteTree(TreeNode*head){
        if(head==nullptr)return true;
        int l=0,r=0;
        std::queue<TreeNode*>que;
        que.push(head);
        //当前结点的左边不为空
        bool leaf=false;
        while(!que.empty()){
            TreeNode*ptr=que.front();
            que.pop();
            //当前结点的左右孩子都不在，或者当前结点的左边没有结点并且左孩子或者右孩子不为空，就不是完全二叉树
            if((ptr->left==nullptr&&ptr->right!=nullptr)||(leaf&&(ptr->left!=nullptr||ptr->right!=nullptr))){
                return false;
            }
            if(ptr->left){
                que.push(ptr->left);
            }
            if(ptr->right){
                que.push(ptr->right);
            }
            if(ptr->left==nullptr||ptr->right==nullptr){
                leaf=true;
            }
        }
        return true;
    }
    //完全二叉树的结点个数
    int f(TreeNode*cur,int level,int h){
        if(level==h)return 1;
        if(mostleft(cur->right,level+1)==h){
            int num=((1<<(h-level))+f(cur->right,level+1,h));
            return num;
        }else{
            int num=((1<<(h-level-1))+f(cur->left,level+1,h));
            return num;
        }
    }
    int mostleft(TreeNode*cur,int level){
        while(cur!=nullptr){
            level++;
            cur=cur->left;
        }
        return level-1;
    }
public:
    //完全二叉树的结点个数
    int countNodes(){
        if(root_==nullptr)return 0;
        int num=f(root_,1,mostleft(root_,1));
        return num;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        return f(root,1,mostleft(root,1));
    }
private:
    //二叉树的最近公共祖先
    TreeNode*lowestCommonAncestor_(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q)return root;
        TreeNode*l=lowestCommonAncestor_(root->left,p,q);
        TreeNode*r=lowestCommonAncestor_(root->right,p,q);
        if(l!=NULL&&r!=NULL)return root;
        if(l==NULL&&r==NULL)return NULL;
        if(l!=NULL)return l;
        else return r;
    }
public:
    //二叉树的最近公共祖先
    TreeNode*lowestCommonAncestor_this(TreeNode*p,TreeNode*q){
        return lowestCommonAncestor_(root_,p,q);
    }
    TreeNode*lowestCommonAncestor_other(TreeNode*root,TreeNode*p,TreeNode*q){
        return lowestCommonAncestor_(root,p,q);
    }

};