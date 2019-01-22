'use strict';

class List {
	constructor() {
		this.data = null;
		this.next = null;
		this.prev = null;
		this.head = null;	
	}
	
	addToBegin(data) {
		if (!this.head) {
  		this.head = new List();
			this.head.data = data;
			this.head.next = null;
			this.head.prev = null;	
			return;
		}

  	let node = new List();
		node.data = data;
		node.next = this.head;
		node.prev = null;
		this.head.prev = node;
		this.head = node;
	}
	
	remove(data) {
		let temp = this.head;
		while (temp) {
  		if (temp.data === data) {
        if (!temp.next) {
          temp.prev.next = null;
          return;
        }
        if (!temp.prev) {
          temp.next.prev = null;
          this.head = temp.next;
          return;
        }
        temp.prev.next = temp.next;
        temp.next.prev = temp.prev;
        return;
      }
			temp = temp.next;
		}
		console.log(`List haven't ${data} element!`);		
	}
	
	print() {
  	let temp = this.head;
		while (temp) {
  		console.log(temp.data);
			temp = temp.next;
		}
	}  
};


