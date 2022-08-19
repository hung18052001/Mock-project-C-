#include "Storage.h"
#include "GamePvP.h"  

class Manage {
    private:
    public:
        void admin_manage(Storage &storage);
		void user_manage(Storage &storage);    
		void sign_up(Storage &storage);    
		bool sign_in_admin(Storage &storage);
        void sign_in_PvP(Storage &storage, Game *&game);    
        
};