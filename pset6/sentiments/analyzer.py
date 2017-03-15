from nltk.tokenize import RegexpTokenizer

class Analyzer():
    """Implements sentiment analysis."""

    def insert(self, file):
        words = set()
        with open(file) as FileObj:
            for line in FileObj:
                if line and not line.startswith(';'): 
                    words.add(line.rstrip());
        return words
    
    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        
        self.positives = self.insert(positives)
        self.negatives = self.insert(negatives)
    
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        
        # tokenize regular expressions only and add then to a set of tokens
        tokenizer = RegexpTokenizer(r'\w+')
        tokens = set(tokenizer.tokenize(text.lower()))
        
        # returns the score of text using intersection of sets
        return len(tokens & self.positives) - len(tokens & self.negatives)