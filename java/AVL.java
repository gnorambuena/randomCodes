
public class AVL implements ArbolBinario {
	NodoAVL root;
	AVL(int n){
		root=new NodoAVL(n);
	}
	public void insertar(int x){
		root=insert(root,x);
	}
	private NodoAVL insert(NodoAVL aux,int x) {
		if(aux==null)return new NodoAVL(x);
		if(x<aux.val){
			aux.left=insert(aux.left,x);
			if(height(aux.left)-height(aux.right)==2){
				if(x < aux.left.val){
					aux = rotateLeft(aux);
				}
				else{
					aux=rotateRightLeft(aux);
				}
			}
		}
		else if(x > aux.val){
			aux.right=insert(aux.right,x);
			if(height(aux.right)-height(aux.left)==2){
				if(x > aux.right.val){
					aux = rotateRight(aux);
				}
				else{
					aux = rotateLeftRight(aux);
				}
			}
		}
		return aux;
	}

	public boolean buscar(int x) {
		NodoAVL aux=root;
		while(aux!=null){
			if(x==aux.val)break;
			else if(x>aux.val)aux=aux.right;
			else aux=aux.left;
		}
		return aux!=null;
	}

	private void lprint(NodoAVL aux){
		if(aux==null)return;
		System.out.println(aux.val);
		lprint(aux.left);
		lprint(aux.right);
	}
	public void print(){
		lprint(root);
	}
	public int altura(){
		return height(root);
	}
	private int height(NodoAVL cur){
		if(cur==null)return 0;
		if(cur.left==null && cur.right==null)return 1;
		if(cur.left==null)return 1+height(cur.right);
		if(cur.right==null)return 1+height(cur.left);
		return 1+Math.max(height(cur.left),height(cur.right));
	}
	
	private NodoAVL rotateRight(NodoAVL cur){
		NodoAVL d=cur.right;
		cur.right=d.left;
		d.left=cur;
		cur.height=Math.max(height(cur.left),height(cur.right))+1;
		d.height=Math.max(height(d.right), cur.height )+1;
		return d;
	}
	private NodoAVL rotateLeft(NodoAVL cur){
		NodoAVL d=cur.left;
		cur.left=d.right;
		d.right=cur;
		cur.height=Math.max( height(cur.left), height(cur.right))+1;
		d.height=Math.max( height(d.left),cur.height)+1;
		return d;
	}
	private NodoAVL rotateLeftRight(NodoAVL cur){
		cur.right=rotateLeft(cur.right);
		return rotateRight(cur);
	}
	private NodoAVL rotateRightLeft(NodoAVL cur){
		cur.left=rotateRight(cur.left);
		return rotateLeft(cur);
	}
}
