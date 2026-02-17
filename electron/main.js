const { app, BrowserWindow, dialog } = require('electron');
const path = require('path');
const { autoUpdater } = require('electron-updater');

let mainWindow;

function createWindow(){
  mainWindow = new BrowserWindow({
    width: 1280,
    height: 720,
    backgroundColor: '#12110f',
    autoHideMenuBar: true,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      contextIsolation: true,
      nodeIntegration: false,
    }
  });

  mainWindow.loadFile(path.join(__dirname, '..', 'Index.html'));
}

app.whenReady().then(() => {
  createWindow();

  if(!app.isPackaged){
    return;
  }

  autoUpdater.checkForUpdatesAndNotify();

  autoUpdater.on('update-downloaded', async () => {
    const { response } = await dialog.showMessageBox({
      type: 'info',
      buttons: ['Restart', 'Later'],
      title: 'Update Ready',
      message: 'A new version is ready. Restart to update?'
    });
    if(response === 0){
      autoUpdater.quitAndInstall();
    }
  });
});

app.on('window-all-closed', () => {
  if(process.platform !== 'darwin') app.quit();
});

app.on('activate', () => {
  if(BrowserWindow.getAllWindows().length === 0) createWindow();
});
