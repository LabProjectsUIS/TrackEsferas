pause(10)
root = 'D:\TrackEsferas\NavarQA\calib';

addpath(genpath(root));
cd(root)
copyfile left\Left*.tif stereo
copyfile right\Right*.tif stereo
clear
clc

robot = java.awt.Robot;
commands = {'cd left';
			'go_calib_optim';
            'Left';
            't';
            '';
            '';
            '';
            '';
            '45';
            '45';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            'saving_calib';
            'cd ..';
            'movefile left\Calib_Results.mat stereo\Calib_Results_left.mat';
            };
        
for c = 1:length(commands)
    sendCmd(robot, commands{c});
end

commands = {'clear';
            'clc';
            'cd right';
            'go_calib_optim';
            'Right';
            't';
            '';
            '';
            '';
            '';
            '45';
            '45';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            '';
            'saving_calib';
            'cd ..';
            'movefile right\Calib_Results.mat stereo\Calib_Results_right.mat';
            };
            

for c = 1:length(commands)
    sendCmd(robot, commands{c});
end

commands = {'cd stereo';
            'load_stereo_calib_files';
            '';
            '';
            'go_calib_stereo';
            'matlab2opencv_bulk'
            };

for c = 1:length(commands)
    sendCmd(robot, commands{c});
end

sendCmd(robot, 'exit');

% commands = {'delete *.tif';
%             'delete *.mat';
%             'cd ..';
%             'delete left\*';
%             'delete right\*';
%             'exit';
%             };
        
commands = {'exit';
            };

for c = 1:length(commands)
    sendCmd(robot, commands{c});
end