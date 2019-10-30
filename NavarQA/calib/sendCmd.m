function sendCmd( robot, c )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

for i = c
    switch i
        case '_'
            robot.keyPress    (java.awt.event.KeyEvent.VK_SHIFT);
            robot.keyPress    (java.awt.event.KeyEvent.VK_MINUS);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_MINUS);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_SHIFT);
        case ' '
            robot.keyPress    (java.awt.event.KeyEvent.VK_SPACE);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_SPACE);
        case '.'
            robot.keyPress    (java.awt.event.KeyEvent.VK_PERIOD);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_PERIOD);
        case '/'
            robot.keyPress    (java.awt.event.KeyEvent.VK_SLASH);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_SLASH);
%             robot.keyPress    (java.awt.event.KeyEvent.VK_ALT);
%             robot.keyPress    (java.awt.event.KeyEvent.VK_NUMPAD4);
%             robot.keyRelease  (java.awt.event.KeyEvent.VK_NUMPAD4);
%             robot.keyPress    (java.awt.event.KeyEvent.VK_NUMPAD7);
%             robot.keyRelease  (java.awt.event.KeyEvent.VK_NUMPAD7);
%             robot.keyRelease  (java.awt.event.KeyEvent.VK_ALT);
        case '\'
            robot.keyPress    (java.awt.event.KeyEvent.VK_SLASH);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_SLASH);
%             robot.keyPress    (java.awt.event.KeyEvent.VK_ALT);
%             robot.keyPress    (java.awt.event.KeyEvent.VK_NUMPAD9);
%             robot.keyRelease  (java.awt.event.KeyEvent.VK_NUMPAD9);
%             robot.keyPress    (java.awt.event.KeyEvent.VK_NUMPAD2);
%             robot.keyRelease  (java.awt.event.KeyEvent.VK_NUMPAD2);
%             robot.keyRelease  (java.awt.event.KeyEvent.VK_ALT);
        case '*'
            robot.keyPress    (java.awt.event.KeyEvent.VK_MULTIPLY);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_MULTIPLY);
        case ':'
            robot.keyPress    (java.awt.event.KeyEvent.VK_COLON);
            robot.keyRelease  (java.awt.event.KeyEvent.VK_COLON);
        otherwise
            if ismember(i, 'A':'Z')
                robot.keyPress    (java.awt.event.KeyEvent.VK_SHIFT);
            end
            format = '(java.awt.event.KeyEvent.VK_%s)';
            key = sprintf(format, upper(i));
            robot.keyPress    (eval(key));
            robot.keyRelease  (eval(key));
            robot.keyRelease  (java.awt.event.KeyEvent.VK_SHIFT);
    end
end
robot.keyPress    (java.awt.event.KeyEvent.VK_ENTER);
robot.keyRelease  (java.awt.event.KeyEvent.VK_ENTER);
end

