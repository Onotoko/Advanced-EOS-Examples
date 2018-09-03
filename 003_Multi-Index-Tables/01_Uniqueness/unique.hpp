#include <eosiolib/eosio.hpp>
#include <string>

using namespace eosio;
using namespace std;

class unique : contract {

	public:

		explicit unique(action_name self) : contract(self) {}
		// @abi action
		void create(const account_name account, const string name, const uint64_t attack);

	private:
		// @abi table items i64
		struct Item {
			uint64_t          id;
			string            name;
			uint64_t          attack;
			account_name      owner;

			auto primary_key() const { return id; };
			EOSLIB_SERIALIZE(Item, (id)(name)(attack));
		};

		typedef multi_index<N(items), Item> items_table;
};

EOSIO_ABI(unique, (create));
