namespace hellmath {

    enum class AccountStatus {
        troll,
        guest,
        user,
        mod
    };

    enum class Action {
        read,
        write,
        remove
    };

    bool display_post(AccountStatus& poster, AccountStatus& viewer) {
        return (poster != AccountStatus::troll) || (viewer == AccountStatus::troll);
    }

    // [read]   -> guest, user, troll, mod
    // [write]  -> user, troll, mod
    // [remove] -> mod
    bool permission_check(Action& action, AccountStatus& as) {
        return (action == Action::read) ||
               (action == Action::write && as != AccountStatus::guest) ||
               (action == Action::remove && as == AccountStatus::mod) ||
               (as == AccountStatus::mod);
    }

    // troll & !troll -> false
    // guest          -> false
    bool valid_player_combination(AccountStatus& as1, AccountStatus& as2) {
        if (
            (as1 == AccountStatus::troll && as2 != AccountStatus::troll) ||
            (as1 != AccountStatus::troll && as2 == AccountStatus::troll)
        ) {
            return false;
        }
        if (as1 == AccountStatus::guest || as2 == AccountStatus::guest) {
            return false;
        }
        
        return true;
    }

    // mod > user > guest > troll
    bool has_priority(AccountStatus& as1, AccountStatus& as2) {
        if (as1 == AccountStatus::troll) {
            return false;
        }
        if ((as1 == AccountStatus::mod && as2 != AccountStatus::mod) || as2 == AccountStatus::troll) {
            return true;
        }
        if (as1 == AccountStatus::user && as2 == AccountStatus::guest) {
            return true;
        }
        
        return false;
    }

}