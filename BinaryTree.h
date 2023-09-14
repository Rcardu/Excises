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
    //�����л�������
    BinaryTree(std::string data):size_(0){StringtoTree(data);}
    //��ǰ�������������
    BinaryTree(std::vector<int>preorder,std::vector<int>midorder):size_(preorder.size()){root_=buildTree(preorder,midorder);}
    ~BinaryTree(){remove(root_);}
public:
    //���л���
    std::string TreetoString(){return deserialize(root_);}
    std::string TreetoString(TreeNode*node){return deserialize(node);}
    //�����л�����������
    void StringtoTree(std::string data){root_=deserialize(data);}
    TreeNode*StringtoTree_val(std::string data){return deserialize(data);}
private:
    //���ڵ�
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
    //�������������������
    TreeNode*buildTree(std::vector<int>preorder,std::vector<int>midorder){
        if(preorder.empty()||midorder.empty()||preorder.size()!=midorder.size())return nullptr;
        std::unordered_map<int,int>map;
        for(int i=0;i<midorder.size();i++)map[midorder[i]]=i;
        return buildTree_(preorder,0,preorder.size()-1,midorder,0,midorder.size()-1,map);
    }
public:
    //����
    bool Insert_left(TreeNode*node,int val){
        if(node==nullptr){
            if(size_==0)return false;//���н�����Ϊ0���Ҵ˽ڵ㲻Ϊ�գ��쳣
            else root_=new TreeNode(val);//����ǰ���Ϊ�գ��ҽ�������Ϊ0�����ڵ�δ����
        }else{
            if(node->left!=nullptr)return false;//�˽ڵ��Ѵ���
            else node->left=new TreeNode(val);
        }
        size_++;
        return true;
    }
    //�ҽ��
    bool Insert_right(TreeNode*node,int val){
        if(node==nullptr){
            if(size_==0)return false;//���н�����Ϊ0���Ҵ˽ڵ㲻Ϊ�գ��쳣
            else root_=new TreeNode(val);//����ǰ���Ϊ�գ��ҽ�������Ϊ0�����ڵ�δ����
        }else{
            if(node->right!=nullptr)return false;//�˽ڵ��Ѵ���
            else node->right=new TreeNode(val);
        }
        size_++;
        return true;
    }
    //ɾ����nodeΪ���ڵ�Ľ�㼰������
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
    //���ͷ���
    TreeNode*Root(){return root_;}
    //��ý���ϵ�ֵ
    int Val(TreeNode*node){return node->val;}
    //�������
    TreeNode*Left(TreeNode*node){return node->left;}
    //����ҽ��
    TreeNode*Right(TreeNode*node){return node->right;}
    //�������������
    int Size(){return size_;}
private:
    //�������л�����ת��Ϊ��
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
        //str��ʣ�µ�Ҳ�Ž�ȥ
        if(!str.empty()){
            Arraydata.push_back(str);
            size_++;
            str.clear();
        }
        return redeserialize(Arraydata);
    }
private:
    /*�������л�*/
    void redeserialize(TreeNode*root,std::string&data){
        if(root==nullptr)data+="#,";
        else{
            data+=std::to_string(root->val)+",";
            redeserialize(root->left,data);
            redeserialize(root->right,data);
        }
    }
    //�����л�
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
    //�ж����Ƿ�ƽ��
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
    //�ж��Ƿ�Ϊ��ȫ������
    bool isCompleteTree(TreeNode*head){
        if(head==nullptr)return true;
        int l=0,r=0;
        std::queue<TreeNode*>que;
        que.push(head);
        //��ǰ������߲�Ϊ��
        bool leaf=false;
        while(!que.empty()){
            TreeNode*ptr=que.front();
            que.pop();
            //��ǰ�������Һ��Ӷ����ڣ����ߵ�ǰ�������û�н�㲢�����ӻ����Һ��Ӳ�Ϊ�գ��Ͳ�����ȫ������
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
    //��ȫ�������Ľ�����
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
    //��ȫ�������Ľ�����
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
    //�������������������
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
    //�������������������
    TreeNode*lowestCommonAncestor_this(TreeNode*p,TreeNode*q){
        return lowestCommonAncestor_(root_,p,q);
    }
    TreeNode*lowestCommonAncestor_other(TreeNode*root,TreeNode*p,TreeNode*q){
        return lowestCommonAncestor_(root,p,q);
    }

};