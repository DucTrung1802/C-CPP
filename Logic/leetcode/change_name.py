INPUT_NAME = "2. Add Two Numbers"

def main():
    output = INPUT_NAME.lower().replace(" ", "_").replace(".", "") + ".cpp"
    print(output)

if __name__ == "__main__":
    main()