#ifndef __AUTOMATIC_SIGNAL_HFA__
#define __AUTOMATIC_SIGNAL_HFA__

// NOTE:
// Your submissions are not accepting AutomaticSignal.hfa
// My compilations use that instead. Please rename this AutomaticSignal.h with the hfa extension.
// Thank you!

#include <monitor.hfa> 		// condition
#include <list.hfa> 		// dlist, dlink

// 
// Implementation source:
//   https://student.cs.uwaterloo.ca/~cs343/protect_V2
//   uCplusplusbook
//   Page 486, Table 9.6
//   (Simulation 3/3)
// 

// ==================== //
// === declarations === //
// ==================== //

// intrusive 
struct IS_NODE_T {
	inline dlink( IS_NODE_T );
	condition cond;
}; // IS_NODE_T

P9_EMBEDDED( IS_NODE_T, dlink( IS_NODE_T ) ); 	// magic :D

struct IS_T {
	dlist( IS_NODE_T ) waiting;
	IS_NODE_T * cursor;
}; // IS

#define AUTOMATIC_SIGNAL IS_T IS


// ================= //
// === waituntil === //
// ================= //

#define WAITUNTIL( pred, before, after )			\
	if ( ! isEmpty( IS.waiting ) || ! (pred) ) {	\
		IS.cursor = &first( IS.waiting ); 			\
		IS_NODE_T IS_node; 							\
		insert_last( IS.waiting, IS_node ); 		\
		for () { 									\
			if ( IS.cursor != 0p ) { 				\
				signal( IS.cursor->cond ); 			\
			} /* if */ 								\
			before; 								\
			wait( IS_node.cond ); 					\
			after; 									\
		  if ( pred ) { break; } 					\
			IS.cursor = &next( IS_node ); 			\
		} /* for */ 								\
		remove( IS_node ); 							\
	} /* if */
// WAITUNTIL


// ======================== //
// === exit / deferexit === //
// ======================== //

#define EXIT()										\
	if ( ! isEmpty( IS.waiting ) ) { 				\
		IS.cursor = &first( IS.waiting ); 			\
		signal( IS.cursor->cond ); 					\
	} /* if */
// EXIT

#define DEFEREXIT() 								\
	struct IS_EXITGUARD_T {}; 						\
	void ^?{}( IS_EXITGUARD_T & ) { EXIT(); } 		\
	IS_EXITGUARD_T IS_EXITGUARD;
// DEFEREXIT


#endif // __AUTOMATIC_SIGNAL_HFA__