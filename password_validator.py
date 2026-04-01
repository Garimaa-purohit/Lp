# Password Strength Validator
# Added for AI code review demonstration - April 2026

def check_password(password):
    # No type checking - potential bug
    errors = []
    
    if len(password) < 8:
        errors.append('Password too short')
    
    has_upper = False
    has_lower = False
    has_digit = False
    has_special = False
    
    for char in password:   # performance: could use regex or any()
        if char.isupper():
            has_upper = True
        if char.islower():
            has_lower = True
        if char.isdigit():
            has_digit = True
        if char in '!@#$%^&*()_+-=':
            has_special = True
    
    if not has_upper:
        errors.append('Missing uppercase letter')
    if not has_lower:
        errors.append('Missing lowercase letter')
    if not has_digit:
        errors.append('Missing digit')
    if not has_special:
        errors.append('Missing special character')
    
    # Security issue: hardcoded common passwords
    common_passwords = ['password', '12345678', 'qwerty123', 'admin123']
    if password.lower() in common_passwords:
        errors.append('Password is too common')
    
    if len(errors) == 0:    # style: use "not errors"
        print('Password is strong!')   # should use logging
        return True
    else:
        print('Weak password: ' + str(errors))  # style: use f-string
        return False

# No main guard - runs on import (bug)
result = check_password('hello')
print('Result: ' + str(result))  # style: use f-string
