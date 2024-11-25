#!/bin/bash

# Check if exactly one argument (PID) is provided
# If not, print an error message and exit
if [ "$#" -ne 1 ]; then
    echo "Give me one more argument: Server PID"
    exit 1
fi

# Store the server PID from the argument
PID=$1

# Random text generator function
# It selects random words from a predefined list to simulate lorem ipsum text
generate_lorem() {
    local words=("lorem" "ipsum" "dolor" "sit" "a" "an" "amet" "consectetur" "adipiscing" "elit" "sed" "do" "eiusmod" "tempor" "incididunt" "ut" "labore" "et" "dolore" "magna" "aliqua")
    # Loop NUM times to generate words
    for ((i=0; i<$NUM; i++)); do
        # Randomly select a word from the list and print it
        printf "%s " "${words[RANDOM % ${#words[@]}]}"
    done
}

# Unicode text generator function
generate_unicode() {
    local words=("U̶n̶i̶c̶o̶d̶e̶ ̶T̶e̶x̶t̶ ̶C̶o̶n̶v̶e̶r̶t̶e̶r̶" "Ⓤⓝⓘⓒⓞⓓⓔ Ⓣⓔⓧⓣ Ⓒⓞ⓷ⓥⓔⓡⓣⓔⓡ" "Ʉ₦ł₵ØĐɆ ₮ɆӾ₮ ₵Ø₦VɆⱤ₮ɆⱤ" "υηι¢σ∂є тєχт ¢σηνєятєя" "приветики" "ɹǝʇɹǝʌuoↃ ʇxǝꓕ ǝpoɔıuꓵ")
    for ((i=0; i<$NUM; i++)); do
        printf "%s " "${words[RANDOM % ${#words[@]}]}"
    done
}

# Array of emojis for random selection later
emojis=("😊" "🚀" "🔥" "🎉" "💡" "💻" "📚" "🧠" "🌟" "✨")

# First loop: 
# Generate simple lorem text and keep running until NUM >= 100
NUM=1
while ((NUM < 100)); do
    lorem_text=$(generate_lorem)
    
    # Send the generated lorem text to the client
    ./client "$PID" "$lorem_text"
    
    NUM=$((NUM + 1))
done

# Second loop: 
# # Generate big lorem text and keep running until NUM >= 5000
NUM=300
while ((NUM < 5000)); do
    lorem_text=$(generate_lorem)
        modified_text=""

    for word in $lorem_text; do
        if ((RANDOM % 10 < 3)); then
            modified_text+="$word${emojis[RANDOM % ${#emojis[@]}]} "
        else
            modified_text+="$word "
        fi
    done

    ./client "$PID" "$modified_text"

    NUM=$(( (NUM + 1) * 2 ))
done

# Third loop: 
# Generate unicode text and keep running until NUM >= 6
NUM=1
while ((NUM < 6)); do
    lorem_text=$(generate_unicode)
    ./client "$PID" "$lorem_text"
    NUM=$((NUM + 1))
done

# Final message indicating the script is done
echo "

I'm done! Bye!

"
