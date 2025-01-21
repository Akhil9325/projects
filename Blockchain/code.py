import hashlib
import time

# Define the Transaction class
class Transaction:
    def __init__(self, sender, receiver, amount):
        self.sender = sender  # username of sender
        self.receiver = receiver  # username of receiver
        self.amount = amount
        self.timestamp = time.time()  # Add timestamp

    def __str__(self):
        return f"{self.sender} sends {self.amount} coins to {self.receiver}"

# Define the Block class
class Block:
    def __init__(self, index, timestamp, transactions, previous_hash, nonce=0):
        self.index = index
        self.timestamp = timestamp
        self.transactions = transactions  # list of Transaction objects
        self.previous_hash = previous_hash
        self.nonce = nonce
        self.hash = self.calculate_hash()

    def calculate_hash(self):
        transactions_data = ''.join(str(tx) for tx in self.transactions)
        block_data = (str(self.index) + str(self.timestamp) +
                      transactions_data + str(self.previous_hash) + str(self.nonce))
        return hashlib.sha256(block_data.encode()).hexdigest()

    def mine_block(self, difficulty):
        target = '0' * difficulty
        while self.hash[:difficulty] != target:
            self.nonce += 1
            self.hash = self.calculate_hash()
        print(f"Block mined: {self.hash}")

# Define the User class
class User:
    def __init__(self, username, password, balance=0):
        self.username = username
        self.password = password
        self.balance = balance

    def check_password(self, password):
        return self.password == password

    def __str__(self):
        return f"User: {self.username}, Balance: {self.balance}"

# Define the Blockchain class
class Blockchain:
    def __init__(self):
        self.chain = [self.create_genesis_block()]
        self.pending_transactions = []
        self.difficulty = 2  # The hash must start with '00'
        self.users = {}  # Dictionary of username: User object

    def create_genesis_block(self):
        genesis_transaction = Transaction("System", "System", 0)
        return Block(0, time.time(), [genesis_transaction], "0")

    def get_latest_block(self):
        return self.chain[-1]

    def add_transaction(self, transaction):
        # Validate transaction before adding to pending transactions
        if self.validate_transaction(transaction):
            self.pending_transactions.append(transaction)
            print("Transaction added to pending transactions.")
        else:
            print("Transaction is invalid and has been rejected.")

    def validate_transaction(self, transaction):
        # Check if sender exists
        if transaction.sender != "System":
            sender = self.users.get(transaction.sender)
            if sender is None:
                print("Sender does not exist.")
                return False
            if sender.balance < transaction.amount:
                print("Sender does not have enough balance.")
                return False
        # Check if receiver exists
        receiver = self.users.get(transaction.receiver)
        if receiver is None and transaction.receiver != "System":
            print("Receiver does not exist.")
            return False
        return True

    def mine_pending_transactions(self, miner_username):
        # Validate miner
        miner = self.users.get(miner_username)
        if miner is None:
            print("Miner does not exist.")
            return

        if not self.pending_transactions:
            print("No transactions to mine.")
            return

        # Sort the pending transactions by amount (descending), then by timestamp (ascending)
        self.pending_transactions.sort(key=lambda tx: (-tx.amount, tx.timestamp))

        valid_transactions = []
        invalid_transactions = []  # List to collect invalid transactions
        # Keep track of balances to ensure transactions are valid
        temp_balances = {user: user_obj.balance for user, user_obj in self.users.items()}

        # Validate transactions and collect valid ones
        for tx in self.pending_transactions:
            if self.validate_transaction_at_mining(tx, temp_balances):
                valid_transactions.append(tx)
                # Update temporary balances
                if tx.sender != "System":
                    temp_balances[tx.sender] -= tx.amount
                if tx.receiver != "System":
                    temp_balances[tx.receiver] += tx.amount
            else:
                print(f"Transaction from {tx.sender} to {tx.receiver} for {tx.amount} coins is invalid at mining time and has been discarded.")
                invalid_transactions.append(tx)  # Collect invalid transactions

        if not valid_transactions:
            print("No valid transactions to mine.")
            return

        # Create new block with all valid transactions
        block = Block(len(self.chain), time.time(),
                      valid_transactions, self.get_latest_block().hash)
        block.mine_block(self.difficulty)

        # Adjust actual balances based on valid transactions
        for tx in valid_transactions:
            if tx.sender != "System":
                sender = self.users[tx.sender]
                sender.balance -= tx.amount
            receiver = self.users.get(tx.receiver)
            if receiver is not None:
                receiver.balance += tx.amount

        # Append the block to the chain
        self.chain.append(block)
        print("Block has been added to the blockchain.")

        # Reward the miner immediately
        miner.balance += 1
        print(f"Miner {miner_username} rewarded with 1 coin.")

        # Remove both mined and invalid transactions from the pending transactions
        self.pending_transactions = [
            tx for tx in self.pending_transactions if tx not in valid_transactions and tx not in invalid_transactions]

    def validate_transaction_at_mining(self, transaction, temp_balances):
        # Ensure sender still has enough balance in temp_balances
        if transaction.sender != "System":
            sender_balance = temp_balances.get(transaction.sender, 0)
            if sender_balance < transaction.amount:
                print(f"Sender {transaction.sender} does not have enough balance at mining time.")
                return False
        # Receiver validation is already done during transaction addition
        return True

    def is_chain_valid(self):
        for i in range(1, len(self.chain)):
            current = self.chain[i]
            previous = self.chain[i-1]

            # Recalculate the hash of the current block
            if current.hash != current.calculate_hash():
                print(f"Block {current.index}: Current hash does not match calculated hash.")
                return False

            # Check if current block's previous hash matches previous block's hash
            if current.previous_hash != previous.hash:
                print(f"Block {current.index}: Previous hash does not match.")
                return False

            # Check proof of work validity
            if current.hash[:self.difficulty] != '0'*self.difficulty:
                print(f"Block {current.index}: Proof of work not valid.")
                return False

        print("Blockchain is valid.")
        return True

    def register_user(self, username, password, balance):
        if username in self.users:
            print("Username already exists.")
            return False
        if username == "System":
            print("Cannot use 'System' as a username.")
            return False
        user = User(username, password, balance)
        self.users[username] = user
        print(f"User {username} has been registered with balance {balance}.")
        return True

    def login_user(self, username, password):
        user = self.users.get(username)
        if user and user.check_password(password):
            print(f"User {username} logged in.")
            return user
        else:
            print("Invalid username or password.")
            return None

    def process_block(self, block):
        # Apply transactions in the block to adjust balances
        for tx in block.transactions:
            if tx.sender != "System":
                sender = self.users.get(tx.sender)
                if sender is None:
                    print(f"Sender {tx.sender} does not exist.")
                    continue
                sender.balance -= tx.amount
            receiver = self.users.get(tx.receiver)
            if receiver is not None:
                receiver.balance += tx.amount
            else:
                print(f"Receiver {tx.receiver} does not exist.")

    def add_block(self, block):
        # Validate block before adding
        if block.previous_hash != self.get_latest_block().hash:
            print("Block's previous hash doesn't match.")
            return False
        if block.hash != block.calculate_hash():
            print("Block hash is invalid.")
            return False
        if block.hash[:self.difficulty] != '0'*self.difficulty:
            print("Block hasn't been mined.")
            return False
        # Add block to chain
        self.chain.append(block)
        # Process transactions in the block
        self.process_block(block)
        print("Block added to the chain.")
        return True

# User interaction
def main():
    blockchain = Blockchain()
    current_user = None

    while True:
        if current_user is None:
            print("\n--- Welcome to the Simple Blockchain ---")
            print("1. Register")
            print("2. Login")
            print("3. Exit")
            choice = input("Enter your choice: ")

            if choice == '1':
                username = input("Enter new username: ")
                password = input("Enter new password: ")
                balance = float(input("Enter initial balance: "))
                blockchain.register_user(username, password, balance)
            elif choice == '2':
                username = input("Enter username: ")
                password = input("Enter password: ")
                user = blockchain.login_user(username, password)
                if user:
                    current_user = user
            elif choice == '3':
                print("Exiting...")
                break
            else:
                print("Invalid choice.")
        else:
            print(f"\n--- Welcome, {current_user.username} ---")
            print("1. View Balance")
            print("2. Send Coins")
            print("3. Mine Pending Transactions")
            print("4. View Blockchain")
            print("5. Validate Blockchain")
            print("6. Logout")
            choice = input("Enter your choice: ")

            if choice == '1':
                print(f"Your balance is: {current_user.balance} coins")
            elif choice == '2':
                receiver = input("Enter receiver's username: ")
                amount = float(input("Enter amount to send: "))
                transaction = Transaction(current_user.username, receiver, amount)
                blockchain.add_transaction(transaction)
            elif choice == '3':
                blockchain.mine_pending_transactions(current_user.username)
            elif choice == '4':
                for block in blockchain.chain:
                    print(f"Block Index: {block.index}")
                    print(f"Timestamp: {block.timestamp}")
                    print("Transactions:")
                    for tx in block.transactions:
                        print(f" - {tx}")
                    print(f"Previous Hash: {block.previous_hash}")
                    print(f"Hash: {block.hash}")
                    print(f"Nonce: {block.nonce}")
                    print("-------------------------------")
            elif choice == '5':
                # Validate the blockchain
                blockchain.is_chain_valid()
            elif choice == '6':
                current_user = None
                print("Logged out.")
            else:
                print("Invalid choice.")

# Run the main function
if __name__ == "__main__":
    main()
