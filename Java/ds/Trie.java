class TrieNode {
	
	char data;
	boolean isTerminating;
	int childCount;
	TrieNode children[];
	
	public TrieNode(char data){
		this.data=data;
		this.childCount=0;
		isTerminating=false;
		children=new TrieNode[26];
	}	
}
public class Trie {

	private TrieNode root;
	
	public Trie() {
		root=new TrieNode('/');
	}
	
//	Function for adding a string in the Trie
	public void add(String str) {
		addHelper(root,0,str);
	}
	
	private void addHelper(TrieNode root,int start,String str) {
		if(start==str.length()) {
			root.isTerminating=true;
			return;
		}
		
		int childIndex=str.charAt(start)-'a';
		TrieNode child=root.children[childIndex];
		
		if(child==null) {
			child=new TrieNode(str.charAt(start));
			root.children[childIndex]=child;
			root.childCount++;
		}
		
		addHelper(child,start+1,str);
		
	}
	
	
//	Function for searching a string in the Trie
	public boolean search(String str) {
		return searchHelper(root,0,str);
	}
	
	private boolean searchHelper(TrieNode root,int start,String str) {
		if(start==str.length()) {
			return root.isTerminating;
		}
		
		int childIndex=str.charAt(start)-'a';
		TrieNode child=root.children[childIndex];
		
		if(child==null) {
			return false;
		}
		
		return searchHelper(child, start+1, str);
	}

	
//	Function for removing string from the Trie
	public void remove(String str) {
		removeHelper(root,0,str);
	}
	
	private void removeHelper(TrieNode root,int start,String str) {
		
		if(start==str.length()) {
			root.isTerminating=false;
			return;
		}
		
		int childIndex=str.charAt(start)-'a';
		TrieNode child=root.children[childIndex];
		
		if(child==null) {
			return;
		}
	
		removeHelper(child, start+1, str);
		
//		We can remove a node only if it is terminating and its number of children are zero
		if(!child.isTerminating) {

			if(child.childCount==0) {
				root.children[childIndex]=null;
				root.childCount--;
				child=null;
			}
		}	
		
	}
	
	
	public static void main(String[] args) {
		
		Trie sample=new Trie();
		
		sample.add("hello");
		sample.add("hell");
		
		System.out.println(sample.search("hello")); //Output : true
		System.out.println(sample.search("hell"));  //Output : true
		
		sample.remove("hell");
		
		System.out.println(sample.search("hell"));  //Output :false
		
	}
		
}

