def deposit(balance, amount):
    return balance + amount

def withdraw(balance, amount):
    if balance >= amount:
        return balance - amount
    else:
        print(f"Withdrawal of {amount} denied due to insufficient funds.")
        return balance

def process_transactions(transactions):
    balance = 0
    for transaction in transactions:
        action, amount = transaction.split()
        amount = int(amount)
        if action == "D":
            balance = deposit(balance, amount)
        elif action == "W":
            balance = withdraw(balance, amount)
        else:
            print(f"Invalid transaction type: {action}")
    return balance

def main():
    print("Enter the transaction log (e.g., D 300, W 200):")
    transaction_log = input("Enter transactions separated by commas: ")
    transactions = [t.strip() for t in transaction_log.split(",")]

    net_balance = process_transactions(transactions)

    print(f"\nNet balance: {net_balance}")

if __name__ == "__main__":
    main()
