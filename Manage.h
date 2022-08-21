<<<<<<< HEAD
#include "Storage.h"
#include "GamePvP.h"  
=======
#ifndef p15
#define p15

#include "GamePvP.h" 
#include "GamePvE.h" 
#include "Storage.h"


>>>>>>> sonth

class Manage {
    private:
    public:
        void admin_manage(Storage &storage);
		void user_manage(Storage &storage);    
		void sign_up(Storage &storage);    
		bool sign_in_admin(Storage &storage);
        void sign_in_PvP(Storage &storage, Game *&game);    
<<<<<<< HEAD
        
};
=======
        void sign_in_PvE(Storage &storage, Game *&game);
};
#endif
>>>>>>> sonth
