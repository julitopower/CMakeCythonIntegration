import web
from adder import PAdder
        
urls = (
    '/(.*)', 'hello'
)
app = web.application(urls, globals())

class hello:
    def __init__(self):
        self.adder = PAdder()
    def POST(self, name):
        return self.adder.add(web.data())

if __name__ == "__main__":
    app.run()
