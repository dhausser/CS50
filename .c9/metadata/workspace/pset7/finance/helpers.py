{"changed":false,"filter":false,"title":"helpers.py","tooltip":"/pset7/finance/helpers.py","value":"import csv\nimport urllib.request\n\nfrom flask import redirect, render_template, request, session, url_for\nfrom functools import wraps\n\ndef apology(top=\"\", bottom=\"\"):\n    \"\"\"Renders message as an apology to user.\"\"\"\n    def escape(s):\n        \"\"\"\n        Escape special characters.\n\n        https://github.com/jacebrowning/memegen#special-characters\n        \"\"\"\n        for old, new in [(\"-\", \"--\"), (\" \", \"-\"), (\"_\", \"__\"), (\"?\", \"~q\"),\n            (\"%\", \"~p\"), (\"#\", \"~h\"), (\"/\", \"~s\"), (\"\\\"\", \"''\")]:\n            s = s.replace(old, new)\n        return s\n    return render_template(\"apology.html\", top=escape(top), bottom=escape(bottom))\n\ndef login_required(f):\n    \"\"\"\n    Decorate routes to require login.\n\n    http://flask.pocoo.org/docs/0.11/patterns/viewdecorators/\n    \"\"\"\n    @wraps(f)\n    def decorated_function(*args, **kwargs):\n        if session.get(\"user_id\") is None:\n            return redirect(url_for(\"login\", next=request.url))\n        return f(*args, **kwargs)\n    return decorated_function\n\ndef lookup(symbol):\n    \"\"\"Look up quote for symbol.\"\"\"\n\n    # reject symbol if it starts with caret\n    if symbol.startswith(\"^\"):\n        return None\n\n    # reject symbol if it contains comma\n    if \",\" in symbol:\n        return None\n\n    # query Yahoo for quote\n    # http://stackoverflow.com/a/21351911\n    try:\n        url = \"http://download.finance.yahoo.com/d/quotes.csv?f=snl1&s={}\".format(symbol)\n        webpage = urllib.request.urlopen(url)\n        datareader = csv.reader(webpage.read().decode(\"utf-8\").splitlines())\n        row = next(datareader)\n    except:\n        return None\n\n    # ensure stock exists\n    try:\n        price = float(row[2])\n    except:\n        return None\n\n    # return stock's name (as a str), price (as a float), and (uppercased) symbol (as a str)\n    return {\n        \"name\": row[1],\n        \"price\": price,\n        \"symbol\": row[0].upper()\n    }\n\ndef usd(value):\n    \"\"\"Formats value as USD.\"\"\"\n    return \"${:,.2f}\".format(value)\n","undoManager":{"mark":-1,"position":-1,"stack":[]},"ace":{"folds":[],"scrolltop":300,"scrollleft":0,"selection":{"start":{"row":60,"column":92},"end":{"row":60,"column":92},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":20,"state":"start","mode":"ace/mode/python"}},"timestamp":1489441274175}