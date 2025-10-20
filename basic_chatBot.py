# Basic Chatbot Program

def chatbot():
    print("Chatbot: Hello! I'm your friendly assistant. Type 'bye' to exit.")
    
    while True:
        user_input = input("You: ").lower()

        if "hello" in user_input or "hii" in user_input:
            print("Chatbot: Hi there!")
        elif "how are you" in user_input:
            print("Chatbot: I'm fine, thanks! How about you?")
        elif "fine" in user_input or "good" in user_input:
            print("Chatbot: Glad to hear that!")
        elif "bye" in user_input:
            print("Chatbot: Goodbye! Have a nice day!")
            break
        else:
            print("Chatbot: Sorry, I didn't understand that.")

# Run the chatbot
chatbot()
