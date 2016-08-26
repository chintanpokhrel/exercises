#include "list.h"

int main(){
	List *l = create_List();
	int i;
	for(i=10; i>0; --i){
		push_List(l, i);
	}
	print_List(l);
	sort_List(l);
	print_List(l);
	destroy_List(l);
	return 0;
}
