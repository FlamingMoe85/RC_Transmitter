
package org.qtproject.example.LightControl1;

import android.content.Context;
import android.media.MediaPlayer;
import android.os.Environment;

public class Mp3PlayerJava extends org.qtproject.qt5.android.bindings.QtActivity {
    private static MediaPlayer mediaPlayer;
    private static Mp3PlayerJava m_instance;

    public Mp3PlayerJava()
    {
        m_instance = this;
        mediaPlayer = new MediaPlayer();

        /**/try
        {
            mediaPlayer.setDataSource("/sdcard/Music/DJKygoISeeFire.mp3");
        }
        catch(Exception e)
        {
            //Handle exception here, most of the time you will just log it.
        }

        try
        {
             mediaPlayer.prepare();
        }
        catch(Exception e)
        {
                    //Handle exception here, most of the time you will just log it.
        }
        //mediaPlayer.start();

    }

        public static void Play()
        {
            mediaPlayer.start();

        }
        public static void Stop()
        {
            mediaPlayer.stop();
        }

        public static void Pause()
        {
            mediaPlayer.pause();
        }

        public static void SetSource(String s)
        {
            try
            {
                mediaPlayer.reset();
            }
            catch(Exception e)
            {
                //Handle exception here, most of the time you will just log it.
            }

            try
            {
                mediaPlayer.setDataSource(s);
            }
            catch(Exception e)
            {
                //Handle exception here, most of the time you will just log it.
            }
            try
            {
                 mediaPlayer.prepare();
            }
            catch(Exception e)
            {
                        //Handle exception here, most of the time you will just log it.
            }
        }

        public static void SeekToMs(int ms)
        {
            mediaPlayer.seekTo(ms);
        }


        public static int GetDuration()
        {
            return mediaPlayer.getDuration();
        }

        public static int GetPosition()
        {
            return mediaPlayer.getCurrentPosition();
        }

}

