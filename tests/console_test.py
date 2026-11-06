import subprocess
import sys

def run(text):
    return subprocess.run([sys.argv[1]],input=text.encode(),capture_output=True,timeout=3,check=True).stdout.decode('utf-8')

assert run('').count('Введіть') <= 1
assert 'Правильно' in run('({[]})\n')
assert 'Правильно' in run('([)]\n[]\n')
assert 'Помилка' in run(')\n')
assert 'Правильно' in run('text without brackets\n')
print('PASS: nesting, mismatch, leading close, plain text and EOF')
